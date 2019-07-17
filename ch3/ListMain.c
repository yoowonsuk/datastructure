#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ArrayList.h"

int main(void)
{
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 11), LInsert(&list, 11);
    LInsert(&list, 22), LInsert(&list, 22);
    LInsert(&list, 33);

    printf("the number of data: %d\n", LCount(&list));

    if(LFirst(&list, &data))
    {
      printf("%d ", data);

      while(LNext(&list, &data))
        printf("%d ", data);
    }
    printf("\n\n");

    if(LFirst(&list, &data))
    {
      if(data == 2)
        LRemove(&list);

      while(LNext(&list, &data))
        if(data == 22)
          LRemove(&list);
    }

    printf("the number of data: %d\n", LCount(&list));

    if(LFirst(&list, &data))
    {
      printf("%d ", data);
      while(LNext(&list, &data))
        printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}
