#include "PriorityQueue.h"
#include <stdio.h>
#include <string.h>

int DataPriorityComp(char * str1, char * str2)
{
  return strlen(str2) - strlen(str1);
}
    
int main(void)
{
  PQueue pq;
  PQueueInit(&pq, DataPriorityComp);

  PEnqueue(&pq, "apple");
  PEnqueue(&pq, "train");
  PEnqueue(&pq, "hope");
  PEnqueue(&pq, "nervous");

  while(!PQIsEmpty(&pq))
    puts(PDequeue(&pq));
  return 0;
}
