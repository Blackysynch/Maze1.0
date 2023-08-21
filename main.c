#include <stdio.h>
#include <SDL2/SDL.h>
#include "main.h"


int main(void){
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	/*game loop*/
	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);

		SDL_RenderDrawLine(instance.renderer, 10,50, 10, 100);
		SDL_RenderDrawPoint(instance.renderer, 10, 40);

		SDL_RenderPresent(instance.renderer);
	}

	return (0);

}
