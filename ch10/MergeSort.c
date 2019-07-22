#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void MergeSort(int [], int, int);
void MergeTwoArea(int[], int, int, int);

int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int i;

	// 배열 arr의 전체 영역 정렬 
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

void MergeSort(int arr[], int left, int right)
{
  if(left==right)
    return;
  MergeSort(arr, left, (left+right)/2);
  MergeSort(arr, (left+right)/2+1, right);
  MergeTwoArea(arr, left, (left+right)/2, right);
}
  

void MergeTwoArea(int arr[], int left, int mid, int right)
{
  int fIdx, rIdx, i;

  int * sortArr = (int *)malloc(sizeof(int) * (right+1));
  int sIdx = left;

  fIdx = left;
  rIdx = mid + 1;

  while(fIdx<mid+1 && rIdx<right+1)
   if(arr[fIdx] < arr[rIdx])
      sortArr[sIdx++] = arr[fIdx++];
    else
      sortArr[sIdx++] = arr[rIdx++];

  if(fIdx == mid+1)
    while(rIdx<right+1)
      sortArr[sIdx++] = arr[rIdx++];
  else
    while(fIdx < mid+1)
      sortArr[sIdx++] = arr[fIdx++];

  for(i=left; i<=right; i++)
    arr[i] = sortArr[i];

  free(sortArr);
}
