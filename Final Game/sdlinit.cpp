#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include "sdlinit.h"



bool windowClass::initialize() {//function starts up SDL, returns true if succesful, returns false if failure
	bool success = true; //variable that will tell if the initialization went alright

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { //If SDL doesn't start
		printf(" SDL could not initialize! SDL_Error: %s\n", SDL_GetError());// Alert of the error and print out which specific error
		//std::cout << "Sdl could not initialize! SDL_Error: " << std::endl << SDL_GetError();// The same thing but in the IOStream library, essentially just how it would look like in C++ rather than C
		success = false;
	}
	else {
		//Create window
		window = SDL_CreateWindow("Final Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);//name, position, position, width, height, idk what the final flag does
		if (window == NULL) {//if the window is nothing, e.g. an error
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;//print out that there was an error and the specific error along with setting success to false
		}
		else {
			//Get window surface if there is no error
			screenSurface = SDL_GetWindowSurface(window);
			//intialize the SDL_Image module if there are no errors
			IMG_Init(IMG_INIT_PNG);
		}
		
	}
	return success;//let's us know if sdl was able to initialize
}

void windowClass::closeSDL() {
	//Deallocate surface
	if(screenSurface != NULL)
		SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	//destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
