#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void InsertionSort(int [], int);

int main(void)
{
 int arr[] = {3, 2, 4, 1};
 int i;

 InsertionSort(arr, sizeof(arr)/sizeof(int));
 for(i=0; i<sizeof(arr)/sizeof(int); i++)
   printf("%d ", arr[i]);
 printf("\n");

 return 0;
}  

void InsertionSort(int arr[], int len)
{
  int i, j, temp;

  for(i=1; i<len; i++)
  {
    temp = arr[i];
    for(j=i-1; j>=0; j--)
      if(temp < arr[j])
        arr[j+1] = arr[j];
      else
        break;

    arr[j+1] = temp;
  }
}

