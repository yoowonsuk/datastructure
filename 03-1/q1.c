#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ArrayList.h"

int main(void)
{
   List list;
   LData data;
   int i;

   ListInit(&list);

   for(i=0; i<9; i++)
     LInsert(&list, i+1);

   if(LFirst(&list, &data))
   {
     printf("%d ", data);
     while(LNext(&list, &data))
       printf("%d ", data);
   }
   printf("\n\n");

   if(LFirst(&list, &data))
   {
     if(!(data % 2) || !(data % 3))
       LRemove(&list);
     while(LNext(&list, &data))
      if(!(data % 2) || !(data % 3))
         LRemove(&list);
   }
   printf("\n\n");

   if(LFirst(&list, &data))
   {
     printf("%d ", data);
     while(LNext(&list, &data))
       printf("%d ", data);
   }
   printf("\n\n");
   return 0;
}
