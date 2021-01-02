#include <string.h> 
#include <stdio.h>
#include "./Color.h"
#include "./PixelData.h"

//
// --- Private Functions ---
//

//
// --- Public Functions ---
//

void PixelDataSetPixel(PixelData_t* pixelData, Color_t* color, int32_t x, int32_t y)
{
  int32_t w = pixelData->w;
  if (x >= 0 && y >= 0 && x < w && y < pixelData->h)
  {
    int32_t index = x + (y * w);
    memcpy((pixelData->pixels) + index, color, sizeof(Pixel_t));
  }
}

void PixelDataDrawVerticalLine(PixelData_t* pixelData, Color_t* color, int32_t x, int32_t y1, int32_t y2)
{
    if (y1 > y2)
    {
      int32_t temp = y1;
      y1 = y2;
      y2 = temp;
    }


    int32_t h = pixelData->h;
    if (y2 >= 0 && y1 < h)
    { 
      y1 = y1 < 0 ? 0 : y1;
      y2 = y2 >= h ? h - 1 : y2;

      for(int32_t y = y1; y <= y2; y++)
      {
        PixelDataSetPixel(pixelData, color, x, y);
      }
    }
}

void PixelDataDrawHorizontalLine(PixelData_t* pixelData, Color_t* color, int32_t y, int32_t x1, int32_t x2)
{
    if (x1 > x2)
    {
      int32_t temp = x1;
      x1 = x2;
      x2 = temp;
    }

    int32_t w = pixelData->w;
    if (x2 >= 0 && x1 < w)
    { 
      x1 = x1 < 0 ? 0 : x1;
      x2 = x2 >= w ? w - 1 : x2;

      for(int32_t x = x1; x <= x2; x++)
      {
        PixelDataSetPixel(pixelData, color, x, y);
      }
    }
}

void PixelDataDrawLine(PixelData_t* pixelData, Color_t* color, int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
  if (x1 == x2)
  {
    PixelDataDrawVerticalLine(pixelData, color, x1, y1, y2);
  }
  else if (y1 == y2)
  {
    PixelDataDrawHorizontalLine(pixelData, color, y1, x1, x2);
  }
  else
  {
      if (x1 > x2)
      {
        int32_t temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = y1;
      }

      int32_t rise = y2 - y1;
      int32_t run = x2 - x1;
      int32_t i = 0;

      if (rise >= run)
      {
        int32_t slope = rise/run;
        
        int32_t segment = 0;
        int32_t total = 0;
        int32_t x = x1;
        int32_t y = y1;
        while (x != x2 && y != y2)
        {
          for ( i = 0; i < slope; i++)
          {
            PixelDataSetPixel(pixelData, color, x, y++);
          }
          total += slope;

          if (2* rise * segment > (2 * total + 1)* run)
          {
            total++;
            PixelDataSetPixel(pixelData, color, x, y++);
          }

          segment++;
          x++;
        }
      }
  }
  
  


}
