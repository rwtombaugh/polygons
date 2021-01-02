#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "./Color.h"
#include "./PixelData.h"

//
// --- Public Types ---
//

typedef struct {
  SDL_Window* window;
  SDL_Renderer* mainRenderer;
  uint32_t windowPixelFormat;
  uint32_t windowWidth;
  uint32_t windowHeigth;
} Game_t;

//
// --- Private Functions ---
//

void GameDraw(Game_t* game)
{
  SDL_Texture* texture = SDL_CreateTexture(
  game->mainRenderer, 
  game->windowPixelFormat, 
  SDL_TEXTUREACCESS_STREAMING,
  game->windowWidth,
  game->windowHeigth);

  Pixel_t* pixels = NULL;
  int32_t pitch = 0;
  SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch);
  PixelData_t pixelData;
  pixelData.w = game->windowWidth;
  pixelData.h = game->windowHeigth;
  pixelData.pixels = pixels;
  Color_t color;
  color.a = 255;
  color.r = 000;
  color.g = 200;
  color.b = 0;
  //PixelDataDrawLine(&pixelData, &color, 50, 50, 50, 100);
  //PixelDataDrawLine(&pixelData, &color, 50, 50, 100, 50);
  PixelDataDrawLine(&pixelData, &color, 50, 50, 80, 100);

  SDL_UnlockTexture(texture);

  SDL_RenderCopy(game->mainRenderer, texture, NULL, NULL);
  SDL_RenderPresent(game->mainRenderer);

  SDL_DestroyTexture(texture);
}

//
// --- Public Functions ---
//

Game_t* GameCreate(SDL_Window* window){
  Game_t* game = (Game_t*)malloc(sizeof(Game_t));
  game->window = window;
  game->windowPixelFormat = SDL_GetWindowPixelFormat(window);
  game->mainRenderer = NULL; 

  int width;
  int height;
  SDL_GetWindowSize(window, &width, &height);
  game->windowWidth = width;
  game->windowHeigth = height;

  return game;
}

void GameDestroy(Game_t** game)
{
  if ((*game)->mainRenderer != NULL)
  {
    SDL_DestroyRenderer((*game)->mainRenderer);
  }

  free(*game);
  *game = NULL;
}

void GameInit(Game_t* game)
{
  game->mainRenderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

  GameDraw(game);
}

void GameHandleEvent(Game_t* game, SDL_Event event)
{
  //GameDraw(game);
}

