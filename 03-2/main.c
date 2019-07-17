#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
  List list;
  NameCard * ptr = NULL;

  ListInit(&list);

  ptr = MakeNameCard("Yoo", "123");
  LInsert(&list, ptr);

  ptr = MakeNameCard("Jung", "234");
  LInsert(&list, ptr);

  ptr = MakeNameCard("James", "345");
  LInsert(&list, ptr);

  if(LFirst(&list, &ptr))
  {
    if(!NameCompare(ptr, "Yoo"))
      ShowNameCardInfo(ptr);
    while(LNext(&list, &ptr))
      if(!NameCompare(ptr, "Yoo"))
        ShowNameCardInfo(ptr);
  }
  printf("\n");
  if(LFirst(&list, &ptr))
  {
    if(!NameCompare(ptr, "Jung"))
      ChangePhoneNum(ptr, "456");
    while(LNext(&list, &ptr))
      if(!NameCompare(ptr, "Jung"))
       ChangePhoneNum(ptr, "456");
   }
    
  if(LFirst(&list, &ptr))
  {
    if(!NameCompare(ptr, "James"))
      LRemove(&list), free(ptr);
    while(LNext(&list, &ptr))
      if(!NameCompare(ptr, "James"))
        LRemove(&list), free(ptr);
  }

  if(LFirst(&list, &ptr))
  {
    ShowNameCardInfo(ptr);
    while(LNext(&list, &ptr))
      ShowNameCardInfo(ptr); 
  }
  printf("\n");
  return 0;
}  
