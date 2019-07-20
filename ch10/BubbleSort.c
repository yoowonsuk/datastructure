#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void BubbleSort(int [], int);

int main(void)
{
 int arr[] = {3, 2, 4, 1};
 int i;

 BubbleSort(arr, sizeof(arr)/sizeof(int));
 for(i=0; i<sizeof(arr)/sizeof(int); i++)
   printf("%d ", arr[i]);
 printf("\n");

 return 0;
}

void BubbleSort(int arr[], int len)
{
  int i, j;
  int temp;

  for(i=0; i<len-1; i++)
    for(j=0; j<(len-1)-i; j++)
      if(arr[j] > arr[j+1])
      {
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
      }
}
