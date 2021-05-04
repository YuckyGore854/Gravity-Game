#include "entity.h"
#include<SDL_image.h>
#include<iostream>


void entity::update() {//keeping it basic
	entRect.x += xVel;
	entRect.y += yVel;
}

void entity::loadSprites(std::string path, SDL_Renderer* renderer) {
	
	SDL_Surface* tempSprites = SDL_CreateRGBSurface(0, 100,100, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	
	tempSprites = IMG_Load(path.c_str());
	sprites = SDL_CreateTextureFromSurface(renderer, tempSprites);

	
	if (sprites == NULL) {
		std::cout << IMG_GetError() << std::endl;
	}
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