/*
Connor Williams
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "dirent.h"
#include <sys/stat.h>
#include "fcntl.h"
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

//prototypes

void getflags(int argc, char **argv);
void getdirs(int argc, char **argv);
void dupdirs();
void processdirs(const char *src, const char*dest);
int CheckDestDIR(const char *dest, char *filename, int *TYPE);
void CopyFULLDirectory(const char *src, const char *dest);
int CompareFilesize( char *pathsrc, char *pathdest);
void CopyFile(char *pathsrc, char *pathdest);
int CompareFilecontents( char *pathsrc, char *pathdest, int bytes);
void MakeBackup(char *pathdest);


//global variables 

int f = 0; //Used for option flags
int v = 0;
int b = 0;
int c = 0;
char* srcdir;
char* destdir;


int main(int argc, char**argv)
{
	getflags(argc, argv); 
	getdirs(argc, argv);
	dupdirs();
	if (v == 1)
		printf("Done!\n");
}

void getflags(int argc, char **argv)
{
	int flags = argc - 3;
	int i = 1;
	while (i <= flags)
	{
		if (strcmp(argv[i],"-F") == 0)
                	f = 1;
		i++;
	}
	i = 1;
        while (i <= flags)
        {
                if (strcmp(argv[i],"-V") == 0)
                        v = 1;
                i++;
        }
	i = 1;
        while (i <= flags)
        {
                if (strcmp(argv[i],"-b") == 0)
                        b = 1;
                i++;
        }
	i = 1;
        while (i <= flags)
        {
                if (strcmp(argv[i],"-c") == 0)
                        c = 1;
                i++;
        }
	return;

}
void getdirs(int argc, char **argv)
{
	int src = argc - 2;
	int dest = argc - 1;
	srcdir = argv[src];
	destdir = argv[dest];
	if (srcdir[0] != '/' || destdir[0] != '/')
	{
		printf("Source directory and/or destination directory is invalid.\n");
		exit(9);
	}
}
void dupdirs()
{
	DIR * src = opendir(srcdir);
	DIR * dest = opendir(destdir);
	if (src == NULL || dest == NULL)
	{
		
		printf("The source directory and/or destination directory failed to open.\n");
		exit(9);
	}
	processdirs(srcdir, destdir);

}
void processdirs(const char *src, const char *dest)
{
    DIR *srcd;
    struct dirent *entry;

    if (!(srcd = opendir(src)))
        return;

    while ((entry = readdir(srcd)) != NULL)
	{
		if (v == 1)
		{
			printf("%s%s\n", "Source path: ", src);
			printf("%s%s\n", "Destination path: ", dest);
		}
		char pathsrc[1024];
		char pathdest[1024];
		int type = 0;
		int *TYPE = &type;
		int match = 0;
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
		if ((match = CheckDestDIR(dest, entry->d_name, TYPE)) == 1) // files have same name
		{
			if (entry->d_type == DT_DIR && *TYPE == 1) //Same name dirs, recurse into both of them
			{	
				if(v == 1)
					printf("Directories have same names, recursing into both...\n");
				snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
				snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
				processdirs(pathsrc, pathdest);
			}
			else
			{
				 //source is a regular file, check if it should be copied
				if(v == 1)
				{
					printf("Source is regular file. Copying source to dest if source is larger...\n");
					printf("%s%s\n", "File name: ", entry->d_name);
				}
				snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
				snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
				int comp = CompareFilesize( pathsrc, pathdest);
				if(comp == 1) //if files differ or if src is larger, copy it to dest
				{
					if (c == 1)
					{
						printf("Copy %s to %s ? [yn]: ", pathsrc, pathdest);
						int a = getchar();
						if ( a == 'y' )
						{
							if (v == 1)
								printf("%s%s\n", "Copying file: ", pathsrc);
							if (b == 1)
								MakeBackup(pathdest);
							CopyFile(pathsrc, pathdest);
						}
					}
					else
					{
						if (v == 1)
							printf("%s%s\n", "Copying file: ", pathsrc);
						if (b = 1)
							MakeBackup(pathdest);
						CopyFile(pathsrc, pathdest);
					}
				}
			}
        } 
		else //file names dont match
		{
			if (entry->d_type == DT_DIR) //source is a directory
			{	
				snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
				snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
				if (v == 1)
					printf("%s%s\n", "Copying directory: ", pathsrc);
				CopyFULLDirectory(pathsrc, pathdest);
			}
			else //source must be a regular file
			{
				snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
				snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
				if (v == 1)
					printf("%s%s\n", "Copying file: ", pathsrc);
				CopyFile(pathsrc, pathdest);
			}
		}
    }
    closedir(srcd);
}
int CheckDestDIR(const char *dest, char* filename, int *TYPE)
{
	DIR *destd;
    struct dirent *entry;

    if (!(destd = opendir(dest)))
        return 0;

    while ((entry = readdir(destd)) != NULL)
	{
        if (strcmp(entry->d_name, filename) == 0)
		{
			if (entry->d_type == DT_DIR)
			{
				*TYPE = 1;
			}
			else
			{
				*TYPE = 0;
			}
			return 1;
        } 
    }

    closedir(destd);
	return 0;
}
void CopyFULLDirectory(const char *src, const char *dest) //copies full directory to dest
{
	
	DIR *srcd;
    struct dirent *entry;
    if (!(srcd = opendir(src)))
        return;
	mkdir(dest, 0777);
	char pathsrc[1024];
	char pathdest[1024];
	
    while ((entry = readdir(srcd)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
		if (entry->d_type == DT_DIR) //if a directory, recurse in
		{
			snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
			snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
			CopyFULLDirectory(pathsrc, pathdest); 
		}
		else //must be a file, copy it to current path
		{
			char buf[1024];
			int fdsrc = 0;
			int fddest = 0;
			snprintf(pathsrc, sizeof(pathsrc), "%s/%s", src, entry->d_name);
			snprintf(pathdest, sizeof(pathdest), "%s/%s", dest, entry->d_name);
			fdsrc = open(pathsrc, O_RDONLY);
				if(fdsrc == -1 && v == 1)
					printf("Source file failed to open\n");
			fddest = open(pathdest, O_CREAT | O_WRONLY, 0777);
				if (fddest == -1 && v == 1)
					printf("Destination file failed to open\n");
				int bytesread = 0;
			while((bytesread = read(fdsrc, buf, 1024))>0)
			{
					write(fddest, buf, bytesread);
					bytesread = 0;
			}
			close(fddest);
			close(fdsrc);
		}
	}
    closedir(srcd);

}
int CompareFilesize( char *src, char *dest) //compares two files sizes, returns largest
{
	if (v == 1)
		printf("Comparing file sizes\n");
	struct stat srcbuf;
	struct stat destbuf;
	stat(src, &srcbuf);
	stat(dest, &destbuf);
	int srcsize = srcbuf.st_size;
	int destsize = destbuf.st_size;
	if (v == 1)
	{
		printf("%s   %s\n", src, dest);
		printf("%s%d   %s%d\n", "Source size: ",srcsize, "Destination size: ",destsize);
	}	
	if (srcsize > destsize)
		return 1;
	
	else if (destsize > srcsize)
		return 2;
	else if (f != 1)
		return CompareFilecontents(src, dest, srcbuf.st_size);
	else return 2;
}
void CopyFile(char *pathsrc, char *pathdest) //copies a file from source to dest
{
	char buf[1024];
	int fdsrc = 0;
	int fddest = 0;
	fdsrc = open(pathsrc, O_RDONLY);
		if(fdsrc == -1 && v == 1)
			printf("Source file failed to open\n");
	fddest = open(pathdest, O_CREAT | O_WRONLY, 0777);
		if (fddest == -1 && v == 1)
			printf("Destination file failed to open\n");
	int bytesread = 0;
	while((bytesread = read(fdsrc, buf, 1024))>0)
	{
			write(fddest, buf, bytesread);
			bytesread = 0;
	}
}
int CompareFilecontents( char *pathsrc, char *pathdest, int bytes)
{
	if (v == 1)
		printf("Comparing file contents\n");
	int fdsrc;
	int fddest;
	char bufsrc[100000];
	char bufdest[100000];
	fdsrc = open(pathsrc, O_RDONLY);
		if(fdsrc == -1 && v == 1)
		{
			printf("Source file failed to open\n");
			return 2;
		}
	fddest = open(pathdest, O_RDONLY);
		if (fddest == -1 && v == 1)
		{
			printf("Source file failed to open\n");
			return 2;
		}
	read(fdsrc, bufsrc, bytes);
	read(fddest, bufdest, bytes);
	if (strcmp(bufsrc, bufdest) == 0)
		return 2;
	else return 1;
}
void MakeBackup(char *pathdest)
{
	struct tm *CURRENT_TIME;
	time_t curTime;
	time(&curTime);
	CURRENT_TIME = localtime(&curTime);
	int hour = CURRENT_TIME->tm_hour;
	int minute = CURRENT_TIME->tm_min;
	int second = CURRENT_TIME->tm_sec;
	int year = 1900 + CURRENT_TIME->tm_year;
	int month = 1 + CURRENT_TIME->tm_mon;
	int day = CURRENT_TIME->tm_mday;
	
	char backupbuf[1024];
	int fdsrc = 0;
	int fddest = 0;
	char BackupDest[1024];
	snprintf(BackupDest, sizeof(BackupDest), "%s.%s-%d_%d_%d-%d.%d.%d", pathdest, "ddup",hour,minute,second,year,month,day );
	fdsrc = open(pathdest, O_RDONLY);
		if(fdsrc == -1 && v == 1)
			printf("Source file failed to open\n");
	fddest = open(BackupDest, O_CREAT | O_WRONLY, 0777);
		if (fddest == -1 && v == 1)
			printf("Destination file failed to open\n");
	int bytesread = 0;
	while((bytesread = read(fdsrc, backupbuf, 1024))>0)
	{
			write(fddest, backupbuf, bytesread);
			bytesread = 0;
	}
}