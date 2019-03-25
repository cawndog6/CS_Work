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

//prototypes

void getflags(int argc, char **argv);
void getdirs(int argc, char **argv);
void copydirs();
void processdirs( struct dirent *dirEntry, DIR* src, char* curpath );
char* getcurpath(char* curpath, char* curfile);
void clear_array(char array[], int size);
void strcopy(char *destination, char *source);

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
	copydirs();
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
void copydirs()
{
	DIR *src = opendir(srcdir);
	DIR *dest = opendir(destdir);
	if (src == NULL || dest == NULL)
	{
		printf("The source directory and/or destination directory failed to open.\n");
		exit(9);
	}
	//original source path(dir)
	char *curpath = srcdir;
	processdirs(readdir(src), src, curpath);

}
void processdirs( struct dirent *dirEntry, DIR *src, char curpath[] )
{
	if(dirEntry != NULL)
	{

		if( strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0)
		{
		
			processdirs(readdir(src), src, curpath);
		}
		else
		{
			printf("%s\n", dirEntry->d_name);
			char *curfile = dirEntry->d_name; //current file name
			char *prevpath = curpath;
			curpath = getcurpath(curpath, curfile); //gets complete file path
			
			struct stat statBuf;
			mode_t mode;
			int result;
			int fd;
			//printf("%s\n", curpath);
			/*fd = open(curpath, O_RDONLY);
				if (fd == -1)
					printf("file failed to open\n");
			result = stat(curpath, &statBuf);
				if (result == -1)
					printf("failed to stat\n");
			*/
			
			
			DIR*subdir = opendir(curpath);
			if(subdir != NULL)
			
				processdirs(readdir(subdir), subdir, curpath);
			
			processdirs(readdir(src), src, prevpath);
			
		}
	}
}
char* getcurpath( char *curpath, char *curfile ) 
{
	char subpath[500];
	clear_array(subpath, 500);
	strcpy(subpath, curpath);
	strcat(subpath, "/");
	strcat(subpath, curfile);
	char * sub_path = subpath;
	return sub_path;
}
void strcopy(char *destination, char *source)
{
		int srclen = strlen(source);
		clear_array(destination, 1000);
		int i = 0;
		while(i < 0)
		{
			destination[i] = source[i];
			i++;
		}
		printf("%s\n", destination);
}

void clear_array(char array[], int size)
{
	int s = 0;
	while (s < size)
	{
		array[s] = '\0';
		s++;
	}
}
