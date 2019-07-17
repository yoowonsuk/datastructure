#ifndef __POINT_H__
#define __POINT_H__

typedef struct
{
  int x;
  int y;
} Point;

void SetPointPos(Point *, int x, int y);
void ShowPointPos(Point *);
int PointComp(Point *, Point *);

#endif
