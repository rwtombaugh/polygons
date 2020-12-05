#include <stdlib.h>
#include "./PointList.h"
#include "./PixelData.h"
#include "./Color.h"

//
// --- Public Types ---
//

typedef struct { 
  PointList_t* points;
  Point_t* center;
  Color_t* color;
} Polygon_t;

//
// --- Public Functions
//

Polygon_t* PolygonCreate(PointList_t* points, Point_t* center, Color_t* color)
{
  Polygon_t* polygon = (Polygon_t*)malloc(sizeof(Polygon_t));
  polygon->points = points;
  polygon->center = center;
  polygon->color = color;

  return polygon;
}

Polygon_t* PolygonCreateTriangle(int32_t radius, Color_t* color)
{
  return NULL;
}

Polygon_t* PolygonCreateSquare(int32_t radius, Color_t* color)
{
  return NULL;
}

Polygon_t* PolygonCreatePentagon(int32_t radius, Color_t* color)
{
  return NULL;
}

Polygon_t* PolygonCreateHexagon(int32_t radius, Color_t* color)
{
  return NULL;
}

void PolygonDestroy(Polygon_t** polygon)
{

}

PixelData_t* PolygonToPixels(Polygon_t* polygon)
{
  return NULL;
}