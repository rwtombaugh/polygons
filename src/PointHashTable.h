#include <stdint.h>
#include <stdbool.h>
#include "./Point.h"

#ifndef PointHashTable_H
#define PointHashTable_H

//
// --- Public Types ---
//

typedef struct { } PointHashTable_t;

//
// --- Public Functions ---
//

PointHashTable_t* PointHashTableCreate(int32_t size);

void PointHashTableDestroy(PointHashTable_t** table);

int32_t PointHashTableSize(PointHashTable_t* table);

void PointHashTableAddPoint(PointHashTable_t* table, Point_t* point);

void PointHashTableAddCoords(PointHashTable_t* table, int32_t x, int32_t y);

bool PointHashTableHasPoint(PointHashTable_t* table, Point_t* point);

bool PointHashTableHasCoords(PointHashTable_t* table, int32_t x, int32_t y);

void PointHashTableRemovePoint(PointHashTable_t* table, Point_t* point);

void PointHashTableRemoveCoords(PointHashTable_t* table, int32_t x, int32_t y);

#endif


