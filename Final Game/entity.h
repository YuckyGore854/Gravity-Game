/**
* This class contains basic variables that entities need
* Game objects such as the player or an enemy will inherit from this class
* polymorphism
*/

#include <SDL.h>
#include <string>
#pragma once
class entity
{
protected://the reason this is protected and not private is that the child class needs access to these variables
	enum direction {
		facingLeft = false,
		facingRight = true
	};
	double xVel = 0;//holds velocity of an entity
	double yVel = 0;
	SDL_Rect entRect;//sdl rect, holds position and rect variables
	SDL_Rect frameRect;
	SDL_Texture* sprites;//creates a sprite for an entity, this holds the image of a particular sprite
public:
	entity();
	void draw(SDL_Renderer* renderer);//drawing function draws to the screen which you pass it
	void update();//update/move just adds velocity to position each frame
	void loadSprites(std::string path, SDL_Renderer* renderer);//loads the image you pass it, second parameter is for keeping the alpha(transparency) of an image
};