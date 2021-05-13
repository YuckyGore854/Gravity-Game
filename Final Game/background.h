#pragma once
#include "entity.h"
#include <SDL.h>
class background : public entity{
public:
	void draw(SDL_Renderer* renderer, float movement);
	background(int x, int y, int w, int h);
private:
	SDL_FRect entRect2 = { entRect.x, entRect.y, entRect.w, entRect.h };
	float currOffset = 0;
	float totalMovement = 0;
};

