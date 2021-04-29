#include<SDL.h>
#include<string>
#pragma once

class windowClass {
public:
	bool initialize();//initialization function
	void closeSDL();//quiting function
	windowClass();
	//bool loadfiles(std::string image);//The functions which load things seem to be bool as a form of defensive coding
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
private:
	
	const int WIDTH = 640;
	const int HEIGHT = 480;
	//The surface contained by the window
	
};