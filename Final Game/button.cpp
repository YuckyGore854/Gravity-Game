#include "button.h"
#include<SDL.h>
#include<iostream>

button::button(int x, int y, int w, int h) {//constructor
	buttonRect.x = x;//setting up the SDL_Rect with the passed variables
	buttonRect.y = y;
	buttonRect.w = w;
	buttonRect.h = h;
}

bool button::isPressed(int x, int y, bool lmouseButtonState) {//the button function
	if (x > buttonRect.x //binding box check with mouse and box
		&& x < buttonRect.x + buttonRect.w
		&& y > buttonRect.y
		&& y < buttonRect.y + buttonRect.h
		&& lmouseButtonState == true) {//the left button must also be clicked to show up along with being inside the button
		buttonPressed = true;
	}
	else {
		buttonPressed = false;
	}
	std::cout << buttonPressed << std::endl;
	return buttonPressed;//returns if it has been pressed
}

void button::draw(SDL_Renderer *renderer) {//draw function, pass it the renderer
	SDL_RenderFillRect(renderer, &buttonRect);//draws rectangle at buttons position and at the renderer
}