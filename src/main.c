#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "./Debug.h"

int main(int argc, char* argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
        SDL_bool done = SDL_FALSE;

        uint32_t pixelFormat = SDL_GetWindowPixelFormat(window);

        SDL_Texture* texture = SDL_CreateTexture(renderer, pixelFormat, SDL_TEXTUREACCESS_STREAMING, 640, 480);

        uint32_t* pixels = NULL;
        int32_t pitch = 0;
        SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch);

        pixels[0] = 0xFFFFFFFF;
        pixels[1] = 0xFFFFFFFF;
        pixels[2] = 0xFFFFFFFF;
        pixels[3] = 0xFFFFFFFF;

        SDL_UnlockTexture(texture);

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
      }
    }

    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
  }
}
