#include "entity.h"


void entity::update() {//keeping it basic
	entRect.x += xVel;
	entRect.y += yVel;
}

void entity::loadSprites(char* filename, SDL_PixelFormat* format) {
	SDL_Surface* tempSprites = NULL;
	tempSprites = SDL_LoadBMP(filename);

	sprites = SDL_ConvertSurface(tempSprites, format, NULL);
}

void entity::draw(SDL_Surface* screen) {
	SDL_BlitSurface(sprites, NULL, screen, &entRect);
}

entity::entity(int x, int y, int width, int height) {
	entRect.x = x;
	entRect.y = y;
	entRect.w = width;
	entRect.h = height;
}