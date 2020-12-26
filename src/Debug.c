#include <SDL2/SDL.h>

//
// --- Public Functions ---
//

void DebugPrintWindowPixelFormat(SDL_Window* window)
{
      SDL_PixelFormat* pixelFormat = SDL_AllocFormat(SDL_GetWindowPixelFormat(window));

      printf("--- DEBUG : Start : Window Pixel Format ---\n");
      printf("Bits Per Pixel:         %d\n", pixelFormat->BitsPerPixel);
      printf("Bytes Per Pixel:        %d\n", pixelFormat->BytesPerPixel);
      printf("Red Component Mask:     %#010x\n", pixelFormat->Rmask);
      printf("Green Component Mask:   %#010x\n", pixelFormat->Gmask);
      printf("Blue Component Mask:    %#010x\n", pixelFormat->Bmask);
      printf("Alpha Component Mask:   %#010x\n", pixelFormat->Amask);
      printf("--- DEBUG : End : Window Pixel Format ---\n");
}
