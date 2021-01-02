#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./Game.h"

int main(int argc, char* argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window* window = SDL_CreateWindow(
      "Polygons", 
      SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED,
      640,
      480,
      0);

    Game_t* game = GameCreate(window);

    GameInit(game);

    bool done = false;
    while (!done)
    {
      SDL_Event event;
      while (SDL_PollEvent(&event)) 
      {
          if (event.type == SDL_QUIT) 
          {
            done = true;
          }
          else
          {
          // GameHandleEvent(game, event);
          }
      }
    }

    GameDestroy(&game);

    if (window) 
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
  }

  return 1;
}
