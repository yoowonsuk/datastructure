#include "DCLLBaseStack.h"
#include <stdlib.h>

void StackInit(Stack * pstack)
{
  pstack->head = (List *)malloc(sizeof(List));
  ListInit(pstack->head);
// pstack->head == NULL;
}

int SIsEmpty(Stack * pstack)
{
  if(LCount(pstack->head))
    return FALSE;
  return TRUE;
  /*
  if(pstack->head == NULL)
    return TRUE;
  return FALSE;
  */
}

void SPush(Stack * pstack, Data data)
{
  LInsertFront(pstack->head, data);
  /*
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;

  newNode->next = pstack->head;
  pstack->head = newNode;
  */
}

Data SPop(Stack * pstack)
{
  Data rdata;
  LFirst(pstack->head, &rdata);
  return LRemove(pstack->head);

  /*
  Data rdata = pstack->head->data;
  Node * ptr = pstack->head->next;

  free(pstack->head);
  pstack->head = ptr;
  return rdata;
  */
}

Data SPeek(Stack * pstack)
{
  Data data;
  LFirst(pstack->head, &data);
  return data;
//  return pstack->head->data;
}

