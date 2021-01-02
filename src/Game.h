#include <SDL2/SDL.h>

#ifndef Game_H
#define Game_H

//
// --- Public Types ---
//

typedef struct {
} Game_t;


//
// --- Public Functions ---
//

Game_t* GameCreate(SDL_Window* window);
void GameDestroy(Game_t** game);

void GameInit(Game_t* game);
void GameHandleEvent(Game_t* game, SDL_Event event);

#endif
