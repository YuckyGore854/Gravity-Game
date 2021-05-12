#pragma once
#include "entity.h"
#include <SDL.h>
class background : public entity{
public:
	void draw(SDL_Renderer* renderer, float offSet);
	background(int x, int y, int w, int h);
private:
	SDL_FRect entRect2 = { entRect.x, entRect.y, entRect.w, entRect.h };
};

