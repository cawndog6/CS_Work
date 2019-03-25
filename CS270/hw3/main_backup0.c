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
//global variables 

int f, v, b, c = 0; //Used for option flags
char* srcdir;
char* destdir;

int main(int argc, char**argv)
{
	getflags(argc, argv);
	getdirs(argc, argv);
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
