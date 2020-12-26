#include "./Point.h"

// 
// --- Public Functions ---
//

Point_t* PointCreate(int x, int y)
{
    Point_t* point = (Point_t*)malloc(sizeof(Point_t));
    point->x = x;
    point->y = y;
    return point;
}
