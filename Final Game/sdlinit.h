#include<SDL.h>
#include<string>
#pragma once

class windowClass {
public:
	bool initialize();//initialization function
	void closeSDL();//quiting function
	windowClass(const int WIDTH, const int HEIGHT);
	//bool loadfiles(std::string image);//The functions which load things seem to be bool as a form of defensive coding
private:
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
};