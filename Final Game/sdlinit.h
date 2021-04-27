#include<SDL.h>
#pragma once


bool initialize(SDL_Window* window, const int WIDTH, const int HEIGHT, SDL_Surface* screenSurface);//initialization function
void closeSDL(SDL_Surface* screenSurface, SDL_Window* window);//quiting function
bool loadfiles();//The functions which load things seem to be bool as a form of defensive coding