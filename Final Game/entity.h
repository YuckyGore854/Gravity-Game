#include <SDL.h>
#pragma once
class entity
{
private:
	double x;
	double y;
	double xVel;
	double yVel;
	SDL_Rect entRect;
public:
	void draw();
	void update();
};

