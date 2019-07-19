#include "DBLinkedList.h"
#include <stdlib.h>

void ListInit(List * plist)
{
  plist->head = NULL;
  plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = plist->head;

  if(plist->head)
    plist->head->prev = newNode;
  
  plist->head = newNode;
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * data)
{
  if(!(plist->numOfData))
    return FALSE;

  plist->cur = plist->head;
  *data = plist->cur->data; 
  return TRUE;
}

int LNext(List * plist, Data * data)
{
  if(plist->cur->next == NULL)
    return FALSE;

  plist->cur = plist->cur->next;
  *data = plist->cur->data;
  return TRUE;
}

int LPrevious(List * plist, Data * data)
{
  if(plist->cur->prev == NULL)
    return FALSE;

  plist->cur = plist->cur->prev;
  *data = plist->cur->data;
  return TRUE;
}
