#include "player.h"
#include<iostream>

player::player(float x, float y, float width, float height) {//constructor, you feed it the position of the entity)
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
		SDL_RenderCopyF(renderer, sprites, &frameRect, &entRect);//begins by rendering a sprite
	else
		SDL_RenderCopyExF(renderer, sprites, &frameRect, &entRect, NULL, NULL, flip);
	ticker++;//ups the ticker
	if (ticker > 6) {//once 6 frames have passed
		ticker = 0;//resets ticker
		frameCounter++;//adds to the frame position
		frameRect.x = frameCounter * 100;//updates the rectangle that holds what we draw
		if (frameCounter > 6)//reset the frame counter if it's too big
			frameCounter = 0;
	}
}

void player::movement(bool up, bool down, bool left, bool right, bool collide) {
	update();
	
	if (xVel < 2 and xVel > -2) {
		if (left) {//accelerates in different directions for different directions
			xVel -= 0.3;
		}
		if (right) {
			xVel += 0.3;
		}
	}
	else
		friction();//slow down in case the velocity exceeds the max speed. prevents unresponsive movement
	if (!left && !right) {//if you aren't moving left or right, slow down to 0
		friction();
	}

	if (up && isOnGround) {
		yVel = -5;
	}
	
	if (xVel > 0) {
		facingRight = true;
	}
	if (xVel < 0) {
		facingRight = false;
	}
	if (collide) {
		isOnGround = true;
	}
	else
		isOnGround = false;

	if (!isOnGround) {
		gravity();
	}

}

void player::friction() {
	xVel *= 0.9;
	yVel *= 0.9;
}

void player::gravity() {
	yVel += 0.1;
}