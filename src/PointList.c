#include <stdlib.h>
#include "./Point.h"

//
// --- Private Types ---
//

typedef struct PointNode_s {
  struct PointNode_s* next;
  Point_t value;
} PointNode_t;

//
// --- Public Types ---
//

typedef struct {
  PointNode_t* head;
  PointNode_t* tail;
  int size;
} PointList_t;

//
// --- Private Functions ---
//

PointNode_t* PointNodeCreate(int x, int y)
{
  PointNode_t* node = (PointNode_t*)malloc(sizeof(PointNode_t));
  node->next = NULL;
  node->value.x = x;
  node->value.y = y;

  return node;
}

//
// --- Public Functions ---
//

PointList_t* PointListCreate()
{
  PointList_t* list = (PointList_t*)malloc(sizeof(PointList_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void PointListDestroy(PointList_t** list)
{
  PointNode_t* node = (*list)->head;
  PointNode_t* toFree;
  while (node != NULL)
  {
    toFree = node;
    node = node->next;
    free(node);
  }

  free(*list);
  *list = NULL;
}

int PointListSize(PointList_t* list)
{
  return list->size;
}

void PointListAddCoords(PointList_t* list, int x, int y)
{
  PointNode_t* node = PointNodeCreate(x, y);
  if (list->head == NULL)
  {
    list->head = node;
    list->tail = node;
    list->size = 1;
  }
  else
  {
    node->next = list->head;
    list->head = node;
    list->size++;
  }  
}

void PointListAddPoint(PointList_t* list, Point_t point)
{
  PointListAddCoords(list, point.x, point.y);
}
