#ifndef _MAIN_H_
#define _MAIN_H_


#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/*for window*/
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int init_instance(SDL_Instance *);


#endif
