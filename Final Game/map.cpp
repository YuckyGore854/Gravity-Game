#include "map.h"
#include<iostream>

void map::draw(SDL_Renderer* renderer) {
	
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 128; j++) {
			if (gameMap[i][j] == 1) {
				SDL_FRect mapRect = { j*20, i*20, 20, 20 };
				SDL_RenderCopyF(renderer, sprites, NULL, &mapRect);
			}
		}
	}
}

map::map() {

}

bool map::collide(float x, float y) {
	int xInt = int(x + 0.5);//converts floating point numbers into integers for collision logic
	int yInt = int(y + 0.5);

	if (gameMap[(yInt + 100) / 20][(xInt + 140) / 24] == 1 || gameMap[(yInt+100)/20][(xInt + 172) / 24] == 1){//checks for collision at the players feet
		return true;//returns true if the player's position is right above a block
	}
	return false;//returns false otherwise
}