#include "stdio.h"
#include "stdlib.h"
//#include "string.h"

//prototypes

int makearg(char *s, char ***args);
int main()
{

	int argc = 0;
	char **argv;
	char input_line[256];
	
	printf("Enter in a line of input: ");
	gets(input_line);
	argc = makearg(input_line, &argv);
	printf("That line contains %d words. They are:\n", argc);
	int y = 0;
	while (y < argc)
	{
		int x = 0;
		while (argv[y][x] != '\0')
		{
			printf("%c", argv[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return 0;


}
int makearg(char *s, char ***args)
{
	int words = 1;
	int spot = 0;
	while (s[spot] == ' ' && s[spot] != '\0') //throws out spaces at the beginning of input data
	{
		spot++;
	}
	if (s[spot] == '\0') //with the while loop above, determines if only spaces were entered.
		return -1;   //If that is true, the function exits with -1.
	while (s[spot] != '\0')
	{
		if( s[spot] == ' ')
		{
			words++;
			while (s[spot] == ' ')
                		spot++;
			continue;
		}
		spot++;
	}
	if (s[spot-1] == ' ') //checks if last character(s) were spaces to accurately return word count.
		words = words - 1;
	spot = 0;
	while (s[spot] == ' ' && s[spot] != '\0') //throws out spaces at the beginning
        {
                spot++;
        }

	*args = malloc(sizeof(char*)*(words));
	int w = 0;
	while (w < words)
	{
		(*args)[w] = malloc(sizeof(char)*64);
		w++;
	}
	//*args[words] = NULL;
	int y = 0;
	while (y < words)
	{
		int x = 0;
		while (s[spot] != ' ')
		{
			(*args)[y][x] = s[spot];
			spot++;
			x++;
		}
		(*args)[y][x] = '\0';
		while (s[spot] == ' ' && s[spot] != '\0')
		{
			spot ++;
		}
		y++;
	}
	
	return words;
}

