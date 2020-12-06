#include <stdlib.h>
#include "./PointList.h"
#include "./PixelData.h"
#include "./Color.h"
#include "./Point.h"
//
// Private Constants
//

const double sqrt3 = 1.73205080757;
const double sqrt2 = 1.41421356237;
const double sin36 = 0.58778525229;
const double cos36 = 0.80901699437;

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
  int c = radius;
  int a = (sqrt3 * c)/2;
  int b = c/2;

  PointList_t* points = PointListCreate();
  PointListAddCoords(points, a, 0);
  PointListAddCoords(points, a * 2, c + b);
  PointListAddCoords(points, 0, c + b);

  return PolygonCreate(points, PointCreate(a, c), color);
}

Polygon_t* PolygonCreateSquare(int32_t radius, Color_t* color)
{
  int c = radius;
  int a = c/sqrt2;

  PointList_t* points = PointListCreate();
  PointListAddCoords(points, 0, 0);
  PointListAddCoords(points, 2 * a, 0);
  PointListAddCoords(points, 2 * a, 2 * a);
  PointListAddCoords(points, 0, 2 * a);
  return PolygonCreate(points, PointCreate(a, a), color);
}

Polygon_t* PolygonCreatePentagon(int32_t radius, Color_t* color)
{
  int c = radius;
  int b = c * sin36;
  int a = c * cos36;
  int e = (2 * b) * cos36;
  int d = (2 * b) * sin36;

  PointList_t* points = PointListCreate();
  PointListAddCoords(points, d, 0);
  PointListAddCoords(points, 2 * d, e);
  PointListAddCoords(points, d + b, c + a);
  PointListAddCoords(points, d - b, c + a);
  PointListAddCoords(points, 0, e);
  return PolygonCreate(points, PointCreate(d, c), color);
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