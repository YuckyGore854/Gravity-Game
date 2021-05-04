#include "entity.h"
#include<SDL_image.h>
#include<iostream>


void entity::update() {//keeping it basic
	entRect.x += xVel;
	entRect.y += yVel;
}

void entity::loadSprites(const char* filename, SDL_Renderer* renderer) {
	SDL_Surface* tempSprites = NULL;
	tempSprites = IMG_Load(filename);

	sprites = SDL_CreateTextureFromSurface(renderer, tempSprites);
	SDL_FreeSurface(tempSprites);
}

void entity::draw(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, sprites, NULL, &entRect);
}

entity::entity(int x, int y, int width, int height) {
	entRect.x = x;
	entRect.y = y;
	entRect.w = width;
	entRect.h = height;
}