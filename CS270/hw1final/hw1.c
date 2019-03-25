#include <stdio.h>
#include <stdlib.h>


const int MAX_SIZE = 10000;
int mainarray[10000];
// Function Prototypes

void populatearray( int a[] );
void copyarray( int main[], int copy[], int size );
int main()
{


	int quick[MAX_SIZE];
	int bubble[MAX_SIZE];
	int insertion[MAX_SIZE];
	
	populatearray( mainarray );
	copyarray( mainarray, quick, MAX_SIZE );
	copyarray( mainarray, bubble, MAX_SIZE );
	copyarray( mainarray, insertion, MAX_SIZE);
	
	quickSort( quick, 0, MAX_SIZE - 1 ); 
	insertionSort( insertion, MAX_SIZE );
	bubbleSort( bubble, MAX_SIZE );






	int g = 0;
	while (g < 10000)
	{
		printf("Quicksort Number: %d -> %d \n", g, quick[g] );
		g++;
	}
	g = 0;
        while (g < 10000)
        {
                printf("InsertionSort Number: %d -> %d \n", g, insertion[g] );
                g++;
        }
	g = 0;
        while (g < 10000)
        {
                printf("BubbleSort Number: %d -> %d \n", g, bubble[g] );
                g++;
        }


}

void copyarray( int main[], int copy[], int size )
{
	int x = 0;
	while ( x < size )
	{
		copy[x] = main[x];
		x++;
	}
}
void populatearray( int a[] )
{
	FILE *pToFile = fopen("numbers.txt", "r");
	int x = 0;
        int num;

        while (!feof(pToFile))
        {
                fscanf(pToFile, "%d",&num);
                a[x] = num;
                x++;

        }
	
}

