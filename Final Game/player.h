#include"entity.h"
#pragma once
class player : public entity{//the player class inherits from the entity class
public:
	player(float x, float y, float width, float height);//constructor, gives position and size of the player
	void movement(bool up, bool down, bool left, bool right);//moves based on the input of the player
	void draw(SDL_Renderer* renderer);//polymorphism!!! replaces the basic entity drawing with a more advanced one.

private:
	int ticker;//variables for drawing spritesheets
	int frameCounter;
	void gravity();
};

