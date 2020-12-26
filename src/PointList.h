#include <stdint.h>
#include <stdbool.h>
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

int32_t PointListSize(PointList_t* list);

void PointListAddPoint(PointList_t* list, Point_t* point);
void PointListAddCoords(PointList_t* list, int32_t x, int32_t y);

void PointListRemovePoint(PointList_t* list, Point_t* point);
void PointListRemoveCoords(PointList_t* list, int32_t x, int32_t y);

bool PointListHasPoint(PointList_t* list, Point_t* point);
bool PointListHasCoords(PointList_t* list, int32_t x, int32_t y);

Point_t PointListGetAtIndex(PointList_t* list, int32_t index);

#endif


