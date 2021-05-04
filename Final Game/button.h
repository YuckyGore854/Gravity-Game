#include<SDL.h>
#pragma once
class button//for cliking a buton and doing stuff
{
private:
	bool buttonPressed = false;//holds if the button instance is pressed
	SDL_Rect buttonRect;//holds the position and size of the button
public:
	bool isPressed(int x, int y, bool LmouseButtonState);//determines if button is clicked from mouse information
	void draw(SDL_Renderer *renderer);//draws the button in the renderer
	button(int x, int y, int w, int h);//constructor, you pass it the position of the button and the size of the button
};