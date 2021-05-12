#include"entity.h"
#pragma once
class player : public entity{//the player class inherits from the entity class
public:
	player(float x, float y, float width, float height);//constructor, gives position and size of the player
	void movement(bool up, bool down, bool left, bool right, bool footCollide);//moves based on the input of the player
	void draw(SDL_Renderer* renderer);//polymorphism!!! replaces the basic entity drawing with a more advanced one
	float getX();//these return the position of the player, used in main to get position
	float getY();
private:
	int ticker = 0;//variables for drawing spritesheets
	int frameCounter = 0;//variable for what frame of animation to draw
	void friction();//slow down with friction
	void gravity();//fall to the ground with gravity
	bool isOnGround = false;//holds if the player is on the ground
	int yDirection = 0;//0 is down, 1 is up
	int playerState = walking;
	enum state {
		walking, jumping, grabbing
	};
	enum verticalDirection {
		DOWN, UP
	};
};

