#include <stdint.h>
#include "./Pixel.h"
#include "./Color.h"

#ifndef PixelData_H
#define PixelData_H

//
// --- Public Types ---
//

typedef struct {
  uint32_t w;
  uint32_t h;
  Pixel_t* pixels;
} PixelData_t;

//
// --- Public Functions ---
//

void PixelDataSetPixel(PixelData_t* pixelData, Color_t* color, int32_t x, int32_t y);
void PixelDataDrawLine(PixelData_t* pixelData, Color_t* color, int32_t x1, int32_t y1, int32_t x2, int32_t y2);

#endif
