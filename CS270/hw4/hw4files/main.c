/*
Connor Williams
4/17/2018
Homework #4
*/
#include "LL.h"
#include "LLr.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//prototypes
void getflags(int argc, char **argv);
void getfilename(int argc, char **argv);
void dash_f_F();
void dash_I();
void dash_r();
void dash_R();
void dash_s();
void dash_H();
void dash_x();
void dash_X();
void selectionSortf(struct LL *arr, int n);
void selectionSortF(struct LL *arr, int n);
void selectionSortR(struct LLr *arr, int n);
char* twosComplement(signed int n);
//global variables
int F = 0;
int H = 0;
int I = 0;
int R = 0;
int X = 0; //flags
int f = 0;
int r = 0;
int s = 0;
int x = 0;
char *file;
char *file2;

int main(int argc, char **argv)
{
	getflags(argc, argv);
	getfilename(argc, argv);
	if (f == 1 || F == 1)
		dash_f_F();
	if (I == 1)
		dash_I();
	if (r == 1)
		dash_r();
	if (R==1)
		dash_R();
	if (s==1)
		dash_s();
	if (H==1)
		dash_H();
	if (x==1)
		dash_x();
	if (X==1)
		dash_X();
}

void getflags(int argc, char **argv)
{
	int flags = argc - 1;
	int i = 1;
	while (i <= flags)
	{
		if (strcmp(argv[i],"-F") == 0)
            F = 1;
		if (strcmp(argv[i], "-H") == 0)
			H = 1;
		if (strcmp(argv[i],"-I") == 0)
			I = 1;
		if (strcmp(argv[i], "-R") == 0)
			R = 1;
		if (strcmp(argv[i],"-X") == 0)
			X = 1;
		if (strcmp(argv[i], "-f") == 0)
			f = 1;
		if (strcmp(argv[i],"-r") == 0)
            r = 1;
		if (strcmp(argv[i], "-s") == 0)
			s = 1;
		if (strcmp(argv[i],"-x") == 0)
                x = 1;
		i++;
	}	
	return;

}
void getfilename(int argc, char **argv)
{
	char *f1; 
	char *f2;
	f1 = argv[argc-2];
	f2 = argv[argc-1];
	if (argv[argc-2][0] == '/' && argv[argc-1][0] == '/')
	{
		file = strdup(f1);
		file2 = strdup(f2);
		printf("%s\n", f1);
		printf("%s\n", file);
	}
	else
	{
		//file = argv[argc-1];
		file = strdup(f2);
		//file = f2;
		
	}
	return;
}
void dash_f_F()
{
	struct LL *head = NULL;
	struct LL *temp = head;
	int fd = open(file, O_RDONLY);
	int bytesread = 0;
	char buff;
	int cont = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		cont = 0;
		if (head == NULL)
		{
			head = (struct LL*)malloc(sizeof(struct LL));
			head->next == NULL;
			head->byte = buff;
			head->frequency = 1;
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				if (temp->byte == buff)
				{
					temp->frequency = temp->frequency + 1;
					cont = 1;
					break;
					
				}
				temp = temp->next;
			}
			if (cont == 1)
				continue;
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = (struct LL*)malloc(sizeof(struct LL));
			temp = temp->next;
			temp->byte = buff;
			temp->frequency = 1;
			temp->next = NULL;
		}
	}
	
	int num_nodes = 0;
	temp = head; //find # of nodes
	while (temp != NULL)
	{
		num_nodes++;
		temp = temp->next;
	}
	struct LL *arr = (struct LL*)malloc(sizeof(struct LL) * num_nodes);
	int i = 0;
	temp = head;
	while (i < num_nodes)
	{
		arr[i] = *temp;
		temp = temp->next;
		i++;
	}
	if (f == 1)
	{
		selectionSortf(arr, num_nodes);
		i = 0;
		printf("ftor -f:\nbyte freq\n==== ====\n");
		while (i < num_nodes)
		{
			printf("0x%x %i\n", arr[i].byte, arr[i].frequency);
			i++;
		}
	}
	if (F == 1)
	{
		selectionSortF(arr, num_nodes);
		i = num_nodes - 1;
		printf("ftor -F\nbyte freq\n==== ====\n");
		while (i >= 0)
		{
			printf("0x%x %i\n", arr[i].byte, arr[i].frequency);
			i--;
		}
	}
	
}
void dash_I()
{
	int fd = open(file, O_RDONLY);
	int bytesread = 0;
	char buff;
	int num_bytes = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		num_bytes++;
	}
	lseek(fd, 0, SEEK_SET);
	char *file_arr = malloc(sizeof(char)*num_bytes);
	int i = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		file_arr[i] = buff;
		i++;
	}
	i = num_bytes - 1;
	while (i >= 0)
	{
		printf("ftor -I:\n%c", file_arr[i]);
		i--;
	}
	
}
void dash_r()
{
	int fd = open(file, O_RDONLY);
	int bytesread = 0;
	char buff;
	int num_bytes = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		num_bytes++;
	}
	lseek(fd, 0, SEEK_SET);
	int *file_arr = malloc(sizeof(char)*num_bytes);
	int i = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		file_arr[i] = buff;
		i++;
	}
	i = 0;
	struct LLr *head = NULL;
	int c;
	int run_size = 0;
	int run_byte_loc = 0;
	while (i < num_bytes)
	{
		run_byte_loc = i;
		run_size = 1;
		c = file_arr[i]; //current character in run
		if (i+1 < num_bytes && c == file_arr[i+1]) //in a run >1
		{
			while(i+1 < num_bytes && c == file_arr[i+1]) //iterate to end of run
			{
				run_size++;
				i++;
			}
			if (head == NULL)
			{
				head = (struct LLr *)malloc(sizeof(struct LLr));
				head->c = c;
				head->run_byte_loc = run_byte_loc;
				head->run_l = run_size;
				head->next = NULL;
			}
			else
			{
				struct LLr *temp = head;
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = (struct LLr *)malloc(sizeof(struct LLr));
				temp = temp->next;
				temp->c = c;
				temp->run_byte_loc = run_byte_loc;
				temp->run_l = run_size;
				temp->next = NULL;
			}
		}
		i++;
	}
	int longest = 0;
	struct LLr *longest_r = head;
	struct LLr *temp = head;
	while (temp != NULL)
	{
		if(temp->run_l > longest_r->run_l)
			longest_r = temp;
		temp = temp->next;
	}
	printf("ftor -r:\n%i 0x%x %i\n", longest_r->run_byte_loc, longest_r->c, longest_r->run_l);
}
void dash_R()
{
	int fd = open(file, O_RDONLY);
	int bytesread = 0;
	char buff;
	int num_bytes = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		num_bytes++;
	}
	lseek(fd, 0, SEEK_SET);
	int *file_arr = malloc(sizeof(char)*num_bytes);
	int i = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		file_arr[i] = buff;
		i++;
	}
	i = 0;
	struct LLr *head = NULL;
	struct LLr *temp = NULL;
	int c;
	int run_size = 0;
	int run_byte_loc = 0;
	while (i < num_bytes)
	{
		run_byte_loc = i;
		run_size = 1;
		c = file_arr[i]; //current character in run
		if (i+1 < num_bytes && c == file_arr[i+1]) //in a run >1
		{
			while(i+1 < num_bytes && c == file_arr[i+1]) //iterate to end of run
			{
				run_size++;
				i++;
			}
			if (head == NULL)
			{
				head = (struct LLr *)malloc(sizeof(struct LLr));
				head->c = c;
				head->run_byte_loc = run_byte_loc;
				head->run_l = run_size;
				head->next = NULL;
			}
			else
			{
				struct LLr *temp = head;
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = (struct LLr *)malloc(sizeof(struct LLr));
				temp = temp->next;
				temp->c = c;
				temp->run_byte_loc = run_byte_loc;
				temp->run_l = run_size;
				temp->next = NULL;
			}
		}
		i++;
	}
	int num_nodes = 0;
	temp = head; //find # of nodes
	while (temp != NULL)
	{
		num_nodes++;
		temp = temp->next;
	}
	struct LLr *arr = (struct LLr*)malloc(sizeof(struct LLr) * num_nodes);
	int t = 0;
	temp = head;
	while (t < num_nodes)
	{
		arr[t] = *temp;
		temp = temp->next;
		t++;
	}
	selectionSortR(arr, num_nodes);
	int k = num_nodes - 1;
	printf("ftor -R:\n"); //print decending order
	while (k >= 0)
	{
		printf("%i 0x%x %i\n", arr[k].run_byte_loc, arr[k].c, arr[k].run_l);
		k--;
	}
}
void dash_s()
{
	int fd = open(file, O_RDONLY); //open file
	int bytesread = 0;
	char buff;
	int num_bytes = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		num_bytes++;//get # bytes
	}
	close(fd);
	printf("ftor -s: %i bytes\n", num_bytes); //print result
	
}
void dash_H()
{
	int fd1 = open(file, O_RDONLY); //open both files
	int fd2 = open(file2, O_RDONLY);
	int bytesread = 0;
	char buff;
	char buff2;
	int num_bytes = 0;
	int num_bytes2 = 0;
	int Ham_distance = 0;
	while ((bytesread = read(fd1, &buff, 1))>0)
	{
		num_bytes++; //get # bytes
	}
	while ((bytesread = read(fd2, &buff, 1))>0)
	{
		num_bytes2++; //get #bytes
	}
	if (num_bytes != num_bytes2)
	{
		printf("ftor -H:\nFiles must be the same size.\n"); //print result
		return;
	}
	else
	{
		lseek(fd1, 0, SEEK_SET); //reset file position to beginning
		lseek(fd2, 0, SEEK_SET);
		while ((bytesread = read(fd1, &buff, 1))>0)
		{
			read(fd2, &buff2, 1);
			if (buff != buff2)
			{
				Ham_distance++;
			}
		}
		//print result
		printf("ftor -H: Hamming distance: %i\n", Ham_distance);
		return;
	}
}
void dash_x()
{
	int fd = open(file, O_RDONLY); //open file
	int bytesread = 0;
	char buff;
	int num_bytes = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		num_bytes++;
	}
	char *arr = malloc(sizeof(char)*num_bytes);
	lseek(fd, 0, SEEK_SET);
	int i = 0;
	while ((bytesread = read(fd, &buff, 1))>0) //place file in array
	{
		arr[i] = buff;
		i++;
	}
	close(fd);
	i = 1;
	int result = 0;
	if(num_bytes == 1)
	{ 
		//print result
		printf("ftor -x:\nFile size = 1 byte. Cannot calculate checksum\n");
		return;
	}
	result = arr[0] ^ arr[1] && i + 1 < num_bytes;
	while (i < num_bytes)
	{
		result = arr[i] ^ arr[i+1];
		i++;
	}
	printf("ftor -x: 0x%x\n", result);
}
void dash_X()
{
	int fd = open(file, O_RDONLY);
	int bytesread = 0;
	char buff;
	short int result = 0;
	while ((bytesread = read(fd, &buff, 1))>0)
	{
		result = result + buff;
	}
	//convert integer to its twos complement
	char *twocmp;
	twocmp = twosComplement(result);
	printf("%i\n", result);
	printf("%s\n", twocmp);
	int t = 15;
	int b = 32768;
	result = 0;
	while(t >=0)
	{
		result = result + (twocmp[t] * b);
		b = b/2;
		t--;
	}
	printf("ftor -X: 0x%x\n", result); //print result
	//result = 
}

void selectionSortf(struct LL *arr, int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].byte < arr[min_idx].byte)
            min_idx = j;
 
        // Swap the found minimum element with the first element
        //swap(&arr[min_idx], &arr[i]);
		int tempbyte = arr[min_idx].byte;
		int tempfreq = arr[min_idx].frequency;
		arr[min_idx].byte = arr[i].byte;
		arr[min_idx].frequency = arr[i].frequency;
		arr[i].byte = tempbyte;
		arr[i].frequency = tempfreq;
    }
}
void selectionSortF(struct LL *arr, int n)
{
    int i, j, min_idx;
	int end = n;
	int start = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].frequency < arr[min_idx].frequency)
            min_idx = j;
 
        // Swap the found minimum element with the first element
        //swap(&arr[min_idx], &arr[i]);
		int tempbyte = arr[min_idx].byte;
		int tempfreq = arr[min_idx].frequency;
		arr[min_idx].byte = arr[i].byte;
		arr[min_idx].frequency = arr[i].frequency;
		arr[i].byte = tempbyte;
		arr[i].frequency = tempfreq;
    }
	
}
void selectionSortR(struct LLr *arr, int n)
{
    int i, j, min_idx;
	int end = n;
	int start = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].run_l < arr[min_idx].run_l)
            min_idx = j;
 
        // Swap the found minimum element with the first element
        //swap(&arr[min_idx], &arr[i]);
		int tempc = arr[min_idx].c;
		int temploc = arr[min_idx].run_byte_loc;
		int templength = arr[min_idx].run_l;
		arr[min_idx].c = arr[i].c;
		arr[min_idx].run_byte_loc = arr[i].run_byte_loc;
		arr[min_idx].run_l = arr[i].run_l;
		arr[i].c = tempc;
		arr[i].run_byte_loc = temploc;
		arr[i].run_l = templength;
    }
	
}
char* twosComplement(signed int n) {
    static char s[17];  // static so the variable persists after the call
    unsigned int i;
    int j;
	int k = 0;
	while (k < 17)
	{
		s[k] = 0;
		k++;
	}
    i = (2<<16)-n; // definition of twos complement

    for(j=0;j<16;j++){
        s[15-j] = ((i&1)==0)?'0':'1'; // test lowest bit
        i=i>>1;                       // right shift by one
    }
    printf("\n"); // just to make output look clean
    s[16]='\0';   // terminate the string
    return s;
}