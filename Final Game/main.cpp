//Using SDL and standard IO
#include<SDL.h>
#include <stdio.h>
#include <iostream>
#include "sdlinit.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//SDL VARIABLES////////////////

//Event handler
SDL_Event e;

//The window we'll be rendering to

window window;

SDL_Renderer* renderer;


//A surface we will use to hold the image
SDL_Surface* drawing = NULL;//name can change I assume you need more of these for more images
//END SDL VARIABLES

int BLACK[3] = { 0,0,0 };

enum GAMESTATE { mainMenu, playing, pause };


int main(int argc, char* args[]) {
	int currGameState = mainMenu;

	bool quit = false;//Main loop variable

	//Initialize SDL
	if (!initialize(window, SCREEN_WIDTH, SCREEN_HEIGHT, screenSurface)) {
		std::cout << "Failed to initialize" << std::endl;
	}

	else {
		renderer = SDL_CreateRenderer(window, -1, 0);
		std::cout << window << std::endl;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//if (!loadfiles(NULL)) {
		//	printf("Failed to load media!\n");
		//}
		//else {
			//GAME LOOP////////////////////////////
			while (!quit) {//while the user doesn't exit the game
				
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) { // SDL_PollEvent checks(polls) for the events of a specific input
					//User requests quit         // in this case the event "&e" represents the red x and if it has been clicked
					if (e.type == SDL_QUIT) {//if the button says quit, set quit to true and end the gameloop
						quit = true;
					}
				}
				//std::cout << screenSurface << std::endl;
				if (screenSurface != NULL) {//so code don't break
					//RENDER SECTION////////////////////////////
					//Fill the surface white
					//std::cout << "Here" << std::endl;
					switch (currGameState) {
					case mainMenu:
						SDL_RenderClear(renderer);
						SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));//colors are in hex rather than base 10, 0x means hex number
						SDL_RenderPresent(renderer);
						SDL_UpdateWindowSurface(window);//goes from memory to the screen
						
						break;
					}

					//Update the surface
					
				}
			}//END GAMELOOP///////////////////////
		//}
	}

	closeSDL(screenSurface, window);//closes SDL
	return 0;//SDL requires main return something at some point hence the return 0
}//END MAIN////////////////////////////////////////////////////////////////////////////////////////////////////
