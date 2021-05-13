#include "background.h"
#include<math.h>

background::background(int x, int y, int w, int h) {
	entRect.x = x;
	entRect.y = y;
	entRect.w = w;
	entRect.h = h;
	entRect2.x = x;
	entRect2.y = y;
	entRect2.h = h;
	entRect2.w = w;
}



void background::draw(SDL_Renderer* renderer, float movement) {
	if (movement > totalMovement || movement < totalMovement)
		currOffset -= movement - totalMovement;
	if (currOffset < -640)
		currOffset = 0;

	

	totalMovement = movement;

	entRect.x = currOffset;
	entRect2.x = currOffset + 640;
	
	

	SDL_RenderCopyF(renderer, sprites, NULL, &entRect);
	SDL_RenderCopyF(renderer, sprites, NULL, &entRect2);
}