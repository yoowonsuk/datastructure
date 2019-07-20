#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "CircularQueue.h"

#define CUS_COME_TERM 15

enum {CHE_BUR, BUL_BUR, DUB_BUR};

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void)
{
    int makeProc = 0;
    int cheOrder, bulOrder, dubOrder;
    int sec;

    cheOrder = bulOrder = dubOrder = 0;

    Queue que;

    QueueInit(&que);
    srand(time(NULL));

    for(sec=0; sec<3600; sec++)
    {
      if(sec % CUS_COME_TERM == 0)
        switch(rand()%3)
        {
        case CHE_BUR:
          Enqueue(&que, CHE_TERM);
          cheOrder++;
          break;
        case BUL_BUR:
          Enqueue(&que, BUL_TERM);
          bulOrder++;
          break;
        case DUB_BUR:
          Enqueue(&que, DUB_TERM);
          dubOrder++;
          break;
        }

      if(!makeProc && !QIsEmpty(&que))
        makeProc = Dequeue(&que);

      makeProc--;
    }

    puts("Simulation Report!");
    printf(" - Cheese burger: %d \n", cheOrder);
  	printf(" - Bulgogi burger: %d \n", bulOrder);
  	printf(" - Double burger: %d \n", dubOrder);
  	printf(" - Waiting room size: %d \n", QUE_LEN);
	  return 0;
}
