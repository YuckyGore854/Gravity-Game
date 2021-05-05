#include "button.h"
#include<SDL.h>
#include<iostream>

button::button(int x, int y, int w, int h) {//constructor
	entRect.x = x;//setting up the SDL_Rect with the passed variables
	entRect.y = y;
	entRect.w = w;
	entRect.h = h;
}

bool button::isPressed(int x, int y, bool lmouseButtonState) {//the button function
	if (x > entRect.x //binding box check with mouse and box
		&& x < entRect.x + entRect.w
		&& y > entRect.y
		&& y < entRect.y + entRect.h
		&& lmouseButtonState == true) {//the left button must also be clicked to show up along with being inside the button
		buttonPressed = true;
	}
	else {
		buttonPressed = false;
	}
	
	return buttonPressed;//returns if it has been pressed
}
