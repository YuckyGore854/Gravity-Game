#include "entity.h"
#include<SDL_image.h>
#include<iostream>


void entity::update() {//keeping it basic as it's just a parent class
	entRect.x += xVel;
	entRect.y += yVel;
}

void entity::loadSprites(std::string path, SDL_Renderer* renderer) {//this function loads a given image into an SDL texture for rendering
	
	SDL_Surface* tempSprites = NULL;//temporary surface is needed, this will be deleted later
	
	tempSprites = IMG_Load(path.c_str());//loads a given string file path into the surface we just made
	sprites = SDL_CreateTextureFromSurface(renderer, tempSprites);//puts the contents of that surface into our classes texture variable
	if (sprites == NULL) {//if the texture is blank meaning something wrong happened
		std::cout << IMG_GetError() << std::endl;//gives us the error
	}
	SDL_FreeSurface(tempSprites);//deletes the temporary surface from memory
}

entity::entity(int x, int y, int w, int h) {
	entRect.x = x;
	entRect.y = y;
	entRect.w = w;
	entRect.h = h;
}

void entity::draw(SDL_Renderer* renderer) {
	SDL_RenderCopyF(renderer, sprites, NULL, &entRect);//copies the entity's texture onto the renderer
	//3rd parameter is for only cutting a chunk of a picture, useful for spritesheets
}

entity::entity() {//constructor just sets up the rectangle and starting position of an entity
	entRect.x = 100;
	entRect.y = 100;
	entRect.w = 100;
	entRect.h = 100;

	frameRect.x = 100;
	frameRect.y = 100;
	frameRect.w = 100;
	frameRect.h = 100;
}

