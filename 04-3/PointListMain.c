#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Point.h"
#include "DLinkedList.h"

int main(void)
{
  List list;
  Point compPos;
  Point * ppos = NULL;
  int i;

  ListInit(&list);

  /*
  ppos = (Point *)malloc(sizeof(Point) * 4);
  for(i=0; i<4; i++)
  {
    SetPointPos(&(ppos[i]), 2 + (i/2), (i%2)+1);
    LInsert(&list, &(ppos[i]);
  }
  */
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 1);
  LInsert(&list, ppos);
  
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 2);
  LInsert(&list, ppos);
  
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 1);
  LInsert(&list, ppos);
  
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 2);
  LInsert(&list, ppos);

  printf("the number of data: %d\n", LCount(&list));

  if(LFirst(&list, &ppos))
  {
    ShowPointPos(ppos);

    while(LNext(&list, &ppos))
      ShowPointPos(ppos);
  }
  printf("\n");

  compPos.x = 2;
  compPos.y = 0;

  if(LFirst(&list, &ppos))
  {
    if(PointComp(ppos, &compPos) == 1)
    {
      ppos = LRemove(&list);
      free(ppos);
    }
  
  while(LNext(&list, &ppos))
    if(PointComp(ppos, &compPos) == 1)
    {
      ppos = LRemove(&list);
      free(ppos);
    }
  }

  printf("the number of data: %d\n", LCount(&list));

  if(LFirst(&list, &ppos))
  {
    ShowPointPos(ppos);

      while(LNext(&list, &ppos))
        ShowPointPos(ppos);
  }
  printf("\n");
  return 0;
}
