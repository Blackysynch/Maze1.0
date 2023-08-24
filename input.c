#include <SDL2/SDL.h>
#include "main.h"
#include <stdlib.h>

void move(double dirX, double dirY, double planeX, double planeY, double posX, double posY, double time, double oldTime, SDL_Event e)
{
	double oldDirX;
	double oldPlaneX;
	double frameTime;/*time the frame took*/
	double moveSpeed;
	double rotSpeed;
	
	oldTime = time;
	time = SDL_GetTicks();
	frameTime = (time - oldTime) / 1000.0;
	printf("%f", 1.0 / frameTime); /*FPS counter*/
	/*redraw();
	 * cls();
	 * */
	moveSpeed = frameTime * 5.0;
	rotSpeed = frameTime * 3.0;

	while (SDL_PollEvent( &e ) != 0)
	{
		/*
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		*/

		/**keyboard press events*/

		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_LEFT:
					oldDirX = dirX;
					dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
					dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
					oldPlaneX = planeX;
					planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
					planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
					break;
				case SDLK_RIGHT:
					oldDirX = dirX;
					dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
					dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
					oldPlaneX = planeX;
					planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
					planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
					break;
				case SDLK_UP:
					if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == false)
						posX += dirX * moveSpeed;
					if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == false)
						 posY += dirY * moveSpeed;
					break;
				case SDLK_DOWN:
					if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == false)
						posX -= dirX * moveSpeed;
					if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == false)
						posY -= dirY * moveSpeed;
					break;
			}

		}
	}
	
}
