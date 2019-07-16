#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int BSearch(int [], int, int);

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
    if(idx == -1)
      puts("can't find!\n");
    else
      printf("find! indix: %d\n", idx);

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx == -1)
      puts("can't find!\n");
    else
      printf("find! indix: %d\n", idx);
    return 0;
}

int BSearch(int arr[], int len, int target)
{
  int first = 0;
  int last = len - 1;
  int mid;
  
  while(first<=last)
  {
    mid = (first+last)/2;
    if(arr[mid]==target)
      return mid;
  
    if(arr[mid] > target)
      last = mid -1;
    else
      first = mid + 1;
  }

  return -1;
}
