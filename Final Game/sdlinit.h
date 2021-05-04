#include<SDL.h>
#include<string>
#pragma once

class windowClass {
public:
	bool initialize();//initialization function
	void closeSDL();//quiting function
	SDL_Window* window = NULL;//window is public as various things call to the window
	SDL_Surface* screenSurface = NULL;//same as screensurface
private:
	const int WIDTH = 640;//determines size of window
	const int HEIGHT = 480;
};