#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ListBaseQueue.h"

#define QUE_LEN 10

void RadixSort(int [], int, int);

int main(void)
{
	int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

void RadixSort(int arr[], int len, int maxlen)
{
  Queue que[QUE_LEN];
  int i, j, k, l, divfac =1;

  for(i=0; i<QUE_LEN; i++)
    QueueInit(&que[i]);

  for(i=0; i<maxlen; i++)
  {
    for(j=0; j<len; j++)
    {
      k = arr[j] / divfac % 10;
      Enqueue(&que[k], arr[j]);
    }

    l=0;
    for(j=0; j<QUE_LEN; j++)
    {
      while(!QIsEmpty(&que[j]))
          arr[l++] = Dequeue(&que[j]);
    }

    divfac *= 10;
  }
}


