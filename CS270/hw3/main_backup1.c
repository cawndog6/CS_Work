/*
Connor Williams
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "dirent.h"

//prototypes

void getflags(int argc, char **argv);
void getdirs(int argc, char **argv);
void copydirs();
void processdirs( struct dirent *dirEntry, DIR* src, char* OG_srcpath );
char* getsubdir(char* curdir);
void clear_array(char array[], int size);
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
	struct dirent *dirEntry; //source dir dirent struct
	if (src == NULL || dest == NULL)
	{
		printf("The source directory and/or destination directory failed to open.\n");
		exit(9);
	}
	char* cur_workingdir = srcdir; //original source path(dir)
	processdirs(dirEntry = readdir(src), src, cur_workingdir);

}
void processdirs( struct dirent *dirEntry, DIR *src, char* cur_workingdir )
{
	if(dirEntry != NULL)
	{

		if( strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0)
		{
		
			processdirs(dirEntry = readdir(src), src);
		}
		else
		{
			printf("%s\n", dirEntry->d_name);
			char* curdir = dirEntry->d_name;
			DIR*subdir = opendir(getsubdir(curdir));
			if (subdir == NULL)
				printf("BROKEN!!!\n");
			processdirs(readdir(subdir), subdir, cur_workingdir);
			processdirs(dirEntry = readdir(src), src, cur_workingdir);
		}
	}
}
char* getsubdir( char*subfile, char* curdir )
{
	char subdir[256];
	clear_array(subdir, 256); 

	char *sub_dir = subdir;
	printf("%s\n", sub_dir);
	return sub_dir;
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

