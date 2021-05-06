#include "player.h"
#include<iostream>

player::player(int x, int y, int width, int height) {//constructor, you feed it the position of the entity)
	entRect.x = x;
	entRect.y = y;
	entRect.w = width;
	entRect.h = height;
	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = width;
	frameRect.h = height;
}

void player::draw(SDL_Renderer* renderer) {
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	
	if (facingRight)
		SDL_RenderCopy(renderer, sprites, &frameRect, &entRect);//begins by rendering a sprite
	else
		SDL_RenderCopyEx(renderer, sprites, &frameRect, &entRect, NULL, NULL, flip);
	ticker++;//ups the ticker
	if (ticker > 6) {//once 6 frames have passed
		ticker = 0;//resets ticker
		frameCounter++;//adds to the frame position
		frameRect.x = frameCounter * 100;//updates the rectangle that holds what we draw
		if (frameCounter > 6)//reset the frame counter if it's too big
			frameCounter = 0;
	}
}

void player::movement(bool left, bool right, bool up, bool down) {
	entRect.x += xVel;
	entRect.y += yVel;
	if (left) {
		facingRight = false;
		xVel = -1;
	}
	if (right) {
		facingRight = true;
		xVel += 1;
	}
	std::cout << facingRight << std::endl;
}