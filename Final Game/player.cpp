#include "player.h"

player::player(float x, float y, float width, float height) {//constructor, you feed it the position of the player
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
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;//this variable is a flag that says to flip an image horizontally
	
	if (facingRight) {
		SDL_RenderCopyF(renderer, sprites, &frameRect, &entRect);
	}
	else
		SDL_RenderCopyExF(renderer, sprites, &frameRect, &entRect, NULL, NULL, flip);//flips the image if the player is facing left

	ticker++;//ups the ticker
	if (ticker > 10) {//once 6 frames have passed
		ticker = 0;//resets ticker
		frameCounter++;//adds to the frame position
		frameRect.x = frameCounter * 100;//updates the rectangle that holds what we draw
		if (frameCounter > 6)//reset the frame counter if it's too big
			frameCounter = 0;
	}
}

void player::movement(bool up, bool down, bool left, bool right, bool footCollide) {
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

	if (up) {//jumps if you're on the ground and press up
		if(isOnGround)
			yVel = -10;
	}
	
	if (xVel > 0) {//changes what direction the player is facing based on the velocity of the player
		facingRight = true;
	}
	if (xVel < 0) {
		facingRight = false;
	}

	if (yVel > 0) {//determines if the player is rising or falling based on y velocity
		yDirection = 0;
	}
	if (yVel < 0) {
		yDirection = 1;
	}

	if (footCollide && yDirection == 0) {//if the player collides with a piece of the map and the player is falling down
		isOnGround = true;
		yVel = 0;
	}
	else
		isOnGround = false;

	if (!isOnGround) {//falls down if the player isn't on the ground
		gravity();
	}

	
}
float player::getX() {
	return entRect.x;
}
float player::getY() {
	return entRect.y;
}

void player::friction() {
	xVel *= 0.9;
}

void player::gravity() {
	yVel *= 0.9;
	yVel += 0.1;
}