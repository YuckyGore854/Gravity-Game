#include "map.h"
#include<iostream>

void map::draw(SDL_Renderer* renderer) {
	
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 128; j++) {
			
			if (gameMap[i][j] == 1) {
				//std::cout << i * 10 << std::endl;
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

	if (gameMap[(yInt + 100) / 20][(xInt + 100)]){
		std::cout << "collide" << std::endl;
		}
}