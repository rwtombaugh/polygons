#include "./PointList.h"
#include "./PixelData.h"
#include "./Color.h"

#ifndef Polygon_t

//
// --- Public Types ---
//

typedef struct { } Polygon_t;

//
// --- Public Functions ---
//

Polygon_t* PolygonCreate(Pointlist_t points, Point_t center, Color_t color);
Polygon_t* PolygonCreateTriangle(int32_t radius);
Polygon_t* PolygonCreateSquare(int32_t radius);
Polygon_t* PolygonCreatePentagon(int32_t radius);
Polygon_t* PolygonCreateHexagon(int32_t radius);

void PolygonDestroy(Polygon_t** polygon);

PixelData_t* PolygonToPixels(Polygon_t* polygon);

#endif
