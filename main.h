#ifndef MAIN_H
#define MAIN_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;

} SDL_Instance;


/*const*/


/*for window*/
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define w screenWidth
#define h screenHeight


int init_instance(SDL_Instance *);
void raycaster();

#endif
