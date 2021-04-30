#include "button.h"
#include<SDL.h>

button::button(int x, int y, int w, int h) {
	buttonRect.x = x;
	buttonRect.y = y;
	buttonRect.w = w;
	buttonRect.h = h;
}

bool button::isPressed(int x, int y, bool lmouseButtonState) {
	if (x > buttonRect.x // binding box check with mouse and box
		&& x < buttonRect.x + buttonRect.w
		&& y > buttonRect.y
		&& y < buttonRect.y + buttonRect.h
		&& lmouseButtonState == true) {
		return true;
	}
	else {
		return false;
	}
}

void button::draw(SDL_Renderer *renderer) {
	SDL_RenderFillRect(renderer, &buttonRect);
}

void button::move() {
	vY = 2;
	buttonRect.y += vY;

}