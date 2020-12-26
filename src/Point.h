#ifndef Point_H
#define Point_H

//
// --- Public Types ---
//

typedef struct {
  int x;
  int y;
} Point_t;

// 
// --- Public Functions ---
//

Point_t* PointCreate(int x, int y);

#endif
