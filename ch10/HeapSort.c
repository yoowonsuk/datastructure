#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
  return n2 - n1;
}

void HeapSort(int [], int n, PriorityComp pc);
      
int main(void)
{
 int arr[] = {3, 2, 4, 1};
 int i;

 HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);
 for(i=0; i<sizeof(arr)/sizeof(int); i++)
   printf("%d ", arr[i]);
 printf("\n");

 return 0;
}

void HeapSort(int arr[], int len, PriorityComp pc)
{
  Heap heap;
  int i;

  HeapInit(&heap, pc);

  for(i=0; i<len; i++)
    HInsert(&heap, arr[i]);

  for(i=0; i<len; i++)
    arr[i] = HDelete(&heap);
}
