#include "player.h"
#include<iostream>

player::player(int x, int y, int width, int height) {//constructor, you feed it the position of the entity)
	entRect.x = x;
	entRect.y = y;
	entRect.w = width;
	entRect.h = height;
	frameRect = entRect;
}

void player::printX() {
	std::cout << entRect.x << " " << entRect.y << std::endl;
}