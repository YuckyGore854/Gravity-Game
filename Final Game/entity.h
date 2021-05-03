/**
* This class contains basic variables that entities need
* Game objects such as the player or an enemy will inherit from this class
* polymorphism
*/

#include <SDL.h>
#pragma once
class entity
{
private:
	double xVel = 0;//holds velocity of an entity
	double yVel = 0;
	SDL_Rect entRect;//sdl rect, holds position and rect variables
	
	SDL_Surface* sprites = NULL;//creates an empty surface for an entity, what will hold the sprite of an entity
public:
	entity(int x, int y, int width, int height);//constructor, you feed it the position of the entity
	void draw(SDL_Surface *screen);//drawing function draws to the screen which you pass it
	void update();//update/move just adds velocity to position each frame
	void loadSprites(char* filename, SDL_PixelFormat* format);//loads the image you pass it, second parameter is for keeping the alpha(transparency) of an image
};

