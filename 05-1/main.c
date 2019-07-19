#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "Employee.h"
#include "CLinkedList.h"

void WhoIsDuty(List * plist, char * name, int day)
{
  int i;
  Employee * who;

  if(day < 1)
  {
    puts("An invalid number");
    return;
  }
  
  LFirst(plist, &who);
  if(strcmp(name, who->name))
    for(i=0; i<LCount(plist)-1; i++)
    {
      LNext(plist, &who);
      if(!(strcmp(name, who->name)))
        break;
    }

  if(i == LCount(plist)-1)
  {
    puts("no name in it");
    return;
  }

  for(i=0; i<day; i++)
    LNext(plist, &who);

  printf("%ddays after %s\n%s(ID: %d) will be serving\n\n", day, name, who->name, who->num);
}


int main(void)
{
    List list;
    Employee * ptr = NULL;
    int i;

    ListInit(&list);

    ptr = (Employee *)malloc(sizeof(Employee));
    ptr -> num = 123;
    strcpy(ptr -> name, "Yoo");
    LInsert(&list, ptr);

    ptr = (Employee *)malloc(sizeof(Employee));
    ptr -> num = 234;
    strcpy(ptr -> name, "Chong");
    LInsert(&list, ptr);

    ptr = (Employee *)malloc(sizeof(Employee));
    ptr -> num = 345;
    strcpy(ptr -> name, "Hong");
    LInsert(&list, ptr);

    ptr = (Employee *)malloc(sizeof(Employee));
    ptr -> num = 456;
    strcpy(ptr -> name, "Oh");
    LInsert(&list, ptr);

    WhoIsDuty(&list, "Yoo", 7);
    WhoIsDuty(&list, "Chong", 3);

    if(LFirst(&list, &ptr))
    {
      free(ptr);
      for(i=0; i<LCount(&list)-1; i++)
        LNext(&list, &ptr), free(ptr);
    }

    return 0;
}
