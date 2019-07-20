#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void SelSort(int [], int);

int main(void)
{
 int arr[] = {3, 2, 4, 1};
 int i;

 SelSort(arr, sizeof(arr)/sizeof(int));
 for(i=0; i<sizeof(arr)/sizeof(int); i++)
   printf("%d ", arr[i]);
 printf("\n");

 return 0;
}   

void SelSort(int arr[], int len)
{
  int i, j, min, temp;

  for(i=0; i<len-1; i++)
  {
    min = i;
    for(j=i+1; j<len; j++)
      if(arr[min] > arr[j])
        min = j;

    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
} 

