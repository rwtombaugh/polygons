#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
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
  int32_t size;
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

int32_t PointListSize(PointList_t* list)
{
  return list->size;
}

void PointListAddCoords(PointList_t* list, int32_t x, int32_t y)
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

void PointListAddPoint(PointList_t* list, Point_t* point)
{
  PointListAddCoords(list, point->x, point->y);
}

bool PointListHasCoords(PointList_t* list, int32_t x, int32_t y)
{
  PointNode_t* node = list->head;
  while (node != NULL)
  {
    if (node->value.x == x && node->value.y == y)
    {
      return true;
    }
    node = node->next;
  }

  return false;
}

bool PointListHasPoint(PointList_t* list, Point_t* point)
{
  return PointListHasCoords(list, point->x, point->y);
}

void PointListRemoveCoords(PointList_t* list, int32_t x, int32_t y)
{
  PointNode_t* node = list->head;
  if (node != NULL)
  {
    if (node->value.x == x && node->value.y == y)
    {
      printf("\n[Removing A] X: %d, Y: %d\n\n", node->value.x, node->value.y);
      list->head = node->next;
      free(node);
      list->size--; 
      PointListRemoveCoords(list, x, y);
      return;
    }

    while (node != NULL)
    {
      PointNode_t* next = node->next;
      if (next != NULL)
      {
        if (next->value.x == x && next->value.y == y)
        {
          printf("\n[Removing B] X: %d, Y: %d\n\n", next->value.x, next->value.y);
          if (next == list->tail)
          {
            list->tail = node;
          }
          node->next = next->next;
          free(next);
          list->size--;
        }
      }

      node = node->next;
    }
  }
}

void PointListRemovePoint(PointList_t* list, Point_t* point)
{
  PointListRemoveCoords(list, point->x, point->y);
}
