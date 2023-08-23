#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"


void raycaster(int worldMap[mapWidth][mapHeight], SDL_Instance instance)
{
	double posX, posY; /*x&y start position*/
	double dirX, dirY; /*initial direction vector*/
	double planeX, planeY; /*the 2d raycaster version of camera plane*/
	/*double time, oldTime; time of current and previous frame*/
	int x;
	double cameraX;
	double rayDirX;
       	double rayDirY;
	int mapX, mapY;
	double sideDistX, sideDistY;/*length of ray from current position to next x or y-side*/
	double deltaDistX, deltaDistY;
	double perpWallDist;

	int stepX, stepY;/*what direction to step in x or y directio (+ or -1)_*/
	int hit, side;/*was a NS or a EW wall hit?*/
	int lineHeight, drawStart, drawEnd;



	posX = 22, posY = 12;
       	dirX = -1, dirY = 0;
	planeX = 0, planeY = 0.66;

	for(x = 0; x < w; x++)
	{
		/*calc ray position and direction*/
		/*x-coordinate in camera space*/
		cameraX = 2 * x / (w * 2) - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		/*which box of the map we're in*/
		mapX = (int)posX;
		mapY = (int)posY;



		/*lenght of ray from one x or y-side to nex */
		deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);


		hit = 0;/*was there a wall hit?*/
		

		/*calc step and initial sideDist*/
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else{
			stepY = 1;
			sideDistX = (mapY + 1.0 - posY) * deltaDistY;

		}

		/*perform DDA*/
		while (hit == 0)
		{
			/*jump to next map square in the x or y direction*/
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			/*check if ray has hit a wall*/
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		/*calc distance projected on camera direction
		 *  euclidean distance would give fish eye effect*/
		if (side == 0){
			perpWallDist = (sideDistX - deltaDistX);
		}
		else{
			perpWallDist = (sideDistY - deltaDistY);
		}
		/*calc height of line to draw on screen*/
		lineHeight = (int)(h /perpWallDist);

		/*calc lowest and highest pixel to fill in current stripe*/
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;

		SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderDrawLine(instance.renderer, x, drawStart, x, drawEnd);

	}
}
