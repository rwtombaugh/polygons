#include <stdint.h>
#include "./Pixel.h"

#ifndef PixelData_t

//
// --- Public Types ---
//

typedef struct {
  int32_t w;
  int32_t h;
  Pixel_t* pixels;
} PixelData_t;

#endif
