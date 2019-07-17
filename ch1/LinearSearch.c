#include <stdio.h>

int LSearch(int arr[], int len, int target)
{
  int i;

  for(i=0; i<len; i++)
    if(arr[i] == target)
      return i;
  return -1;
}

int main(void)
{
  int arr[] = {3, 5, 2, 4, 9};
  int i;

  i = LSearch(arr, sizeof(arr)/sizeof(int), 3);
  if(i == -1)
    puts("can't find");
  else
    printf("find! index: %d\n", i);

  i = LSearch(arr, sizeof(arr)/sizeof(int), 7);
  if(i == -1)
    puts("can't find");
  else
    printf("find! index: %d\n", i);
}
  
