#include"entity.h"
#pragma once
class player : public entity{//the player class inherits from the entity class
public:
	player(int x, int y, int width, int height);
	void movement(bool left, bool right, bool up, bool down);
	void printX();
};

