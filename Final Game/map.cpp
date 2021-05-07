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