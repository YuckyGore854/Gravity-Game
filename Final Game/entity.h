/**
* This class contains basic variables that entities need
* Game objects such as the player or an enemy will inherit from this class
* polymorphism
*/

#include <SDL.h>
#include<iostream>
#include<SDL_image.h>
#include <string>
#pragma once
class entity
{
protected://the reason this is protected and not private is that the child class needs access to these variables
	bool facingRight = true;
	int gameState = 0;
	float xVel = 0;//holds velocity of an entity
	float yVel = 0;
	SDL_FRect entRect;//sdl rect, holds position and rect variables
	SDL_Rect frameRect;//this rect holds which frame of animation the entity is on
	SDL_Texture* sprites;//creates a sprite for an entity, this holds the image of a particular sprite
public:
	entity();
	entity(int x, int y, int w, int h);
	void draw(SDL_Renderer* renderer);//drawing function draws to the screen which you pass it
	void update();//update/move just adds velocity to position each frame
	void loadSprites(std::string path, SDL_Renderer* renderer);//loads the image you pass it, second parameter is for keeping the alpha(transparency) of an image
};