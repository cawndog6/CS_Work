// Bubble sort algo
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   i = 0;
   while( i < n-1 )
   {    
       j = 0;
       while ( j < n-i-1 )   
       { 
           if (arr[j] > arr[j+1])
	   {
              swap(&arr[j], &arr[j+1]);
	   }
	j++;
        }
   i++;
   }

}	  
