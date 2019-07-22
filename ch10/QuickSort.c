#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void Swap(int [], int, int);
int Partition(int [], int, int);
void QuickSort(int [], int, int);

int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
//	int arr[3] = {3, 3, 3};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

void QuickSort(int arr[], int left, int right)
{
  if(left < right)
  {
    int partition = Partition(arr, left, right);
    QuickSort(arr, left, partition-1);
    QuickSort(arr, partition+1, right);
  }
}

int Partition(int arr[], int left, int right)
{
  int low = left + 1;
  int high = right;
  int pivot = arr[left];

  while(low<=high)
  {
    while(pivot >= arr[low] && low<=right)
      low++;
    while(pivot <= arr[high] && high >= left+1)
      high--;

    if(low<high)
      Swap(arr, low, high);
  }

  Swap(arr, high, left);
  return high;
}

void Swap(int arr[], int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}
