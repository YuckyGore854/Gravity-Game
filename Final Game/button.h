#include<SDL.h>
#pragma once
class button
{
private:
	bool buttonPressed = false;
	SDL_Rect buttonRect;
	double vY = 0;
public:
	bool isPressed(int x, int y, bool LmouseButtonState);
	void draw(SDL_Renderer *renderer);
	button(int x, int y, int w, int h);
	void move();

};
