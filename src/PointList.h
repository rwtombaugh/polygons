#include "./Point.h"

#ifndef PointList_H
#define PointList_H

//
// --- Public Types ---
//

typedef struct { } PointList_t;

//
// --- Public Functions ---
//

PointList_t* PointListCreate();
void PointListDestroy(PointList_t** list);

int PointListSize(PointList_t* list);

void PointListAddPoint(PointList_t* list, Point_t point);
void PointListAddCoords(PointList_t* list, int x, int y);

Point_t PointListGetAtIndex(PointList_t* list, int index);

#endif


