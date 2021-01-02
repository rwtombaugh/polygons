#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Point.h"
#include "./PointList.h"

//
// --- Public Types ---
//

typedef struct { 
  PointList_t** lists;
  int32_t tableSize;
  int32_t size;
} PointHashTable_t;

// --- Private Function ---

int32_t GetHashTableIndex(int32_t x, int32_t y, int32_t tableSize)
{
  return (x + y) % tableSize;
}

//
// --- Public Functions ---
//

PointHashTable_t* PointHashTableCreate(int32_t tableSize)
{
  PointHashTable_t* table = (PointHashTable_t*)malloc(sizeof(PointHashTable_t));

  table->lists = (PointList_t**)malloc(sizeof(PointList_t*) * tableSize);
  for (int32_t i = 0; i < tableSize; i++)
  {
    (table->lists)[i] = NULL;
  }

  table->tableSize = tableSize;
  table->size = 0;

  return table;
}

void PointHashTableDestroy(PointHashTable_t** table)
{
  for (int32_t i = 0; i < (*table)->tableSize; i++)
  {
    PointList_t* list = ((*table)->lists)[i];
    if (list != NULL)
    {
      PointListDestroy(&list);
    }
  }

  free((*table)->lists);
  free(*table);

  *table = NULL;
}

int32_t PointHashTableSize(PointHashTable_t* table)
{
  return table->size;
}

void PointHashTableAddCoords(PointHashTable_t* table, int32_t x, int32_t y)
{
  int32_t index = GetHashTableIndex(x, y, table->tableSize);

  PointList_t* list = (table->lists)[index];

  if (list == NULL)
  {
    list = PointListCreate();
    (table->lists)[index] = list;
  }

  PointListAddCoords(list, x, y);

  table->size++;
}

void PointHashTableAddPoint(PointHashTable_t* table, Point_t* point)
{
  PointHashTableAddCoords(table, point->x, point->y);
}

bool PointHashTableHasCoords(PointHashTable_t* table, int32_t x, int32_t y)
{
  int32_t index = GetHashTableIndex(x, y, table->tableSize);

  PointList_t* list = (table->lists)[index];

  if (list == NULL)
  {
    return false;
  }

  return PointListHasCoords(list, x, y);
}

bool PointHashTableHasPoint(PointHashTable_t* table, Point_t* point)
{
  return PointHashTableHasCoords(table, point->x, point->y);
}

void PointHashTableRemoveCoords(PointHashTable_t* table, int32_t x, int32_t y)
{
  int32_t index = GetHashTableIndex(x, y, table->tableSize);

  PointList_t* list = (table->lists)[index];

  if (list != NULL)
  {
    PointListRemoveCoords(list, x, y);
  }
}

void PointHashTableRemovePoint(PointHashTable_t* table, Point_t* point)
{
  PointHashTableRemoveCoords(table, point->x, point->y); 
}
