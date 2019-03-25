#include "stdio.h"

//function prototypes

void findstate (char buffer[]);
void clearbuffer (char buffer[]);
int findsize (char buffer[]);
void printlexeme (char buffer[]);
 
//global variables

int buffspot = 1;
int state = 0;
int prevstate = 0; 

int main()
{
	printf("hello");
	char buffer[257];
	FILE *fIn = fopen("hello_world.ccx", "r");
	clearbuffer (buffer);
	while (!feof(fIn));
	{
		buffer[buffspot] = fgetc(fIn);
		printf("%s", "hello");
		buffspot++;
		//findstate (buffer);
		
	}

}

void clearbuffer (char buffer[])
{
	int i = 0;
	while (i < 257)
	{
		buffer[i] = '\0';
		i++;
	}
}

int findsize (char buffer[])
{
	int i = 0;
	while (buffer[i] != '\0')
	{
		i++;
	}
	return i;
}

void findstate (char buffer[])
{
	prevstate = state;
	if (buffer[buffspot] == '*' && buffer[buffspot - 1] == '/')
	{
		state = 1;
	}
	if (state == 1)
	{
		if (buffer[buffspot] == '/' && buffer[buffspot - 1] == '*')
			printlexeme(buffer);
	}
	else 
		state = 0;

}
void printlexeme (char buffer[])
{
	int i = 1;
	while (buffer[i] != '\0')
		printf("%c", buffer[i]);
	if (state == 1)
		printf("%s", "(Comment)");
	clearbuffer(buffer);
}
