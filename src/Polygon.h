#include "./PointList.h"
#include "./PixelData.h"
#include "./Color.h"

#ifndef Polygon_H
#define Polygon_H

//
// --- Public Types ---
//

typedef struct { } Polygon_t;

//
// --- Public Functions ---
//

Polygon_t* PolygonCreate(PointList_t* points, Point_t* center, Color_t* color);
Polygon_t* PolygonCreateTriangle(int32_t radius, Color_t* color);
Polygon_t* PolygonCreateSquare(int32_t radius, Color_t* color);
Polygon_t* PolygonCreatePentagon(int32_t radius, Color_t* color);
Polygon_t* PolygonCreateHexagon(int32_t radius, Color_t* color);

void PolygonDestroy(Polygon_t** polygon);

PixelData_t* PolygonToPixels(Polygon_t* polygon);

#endif
