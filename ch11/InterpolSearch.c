#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int ISearch(int [], int, int, int);

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;
	
	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 9);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}

int ISearch(int arr[], int left, int right, int target)
{
  int idx;

  while(arr[right] >= target && target >= arr[left])
  {
     idx = (double)(target-arr[left]) / (arr[right]-arr[left]) * (right-left) + left;

     if(target == arr[idx])
      return idx;
     else if(arr[idx] > target)
      right = idx-1;
     else
      left = idx+1;
  }
  return -1;
}
