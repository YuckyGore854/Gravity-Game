#include <SDL.h>//SDL library
#include <SDL_image.h>//SDL image library for loading pngs
#include <stdio.h>
#include <iostream>//basic io
#include <vector>
#include "sdlinit.h"//custom file that creates a window
#include "button.h"//creates a button
#include "entity.h"//parent class of most things
#include "player.h"//player

using namespace std;//generally bad practice but this is a small project without many moving parts

//SDL VARIABLES////////////////

//spawn a window class
windowClass window;

//create a renderer 
SDL_Renderer* renderer;//the renderer was introduced in SDL2
//allows the GPU to draw things rather than relying on the CPU, resulting in faster code

//END SDL VARIABLES

//GAME/INPUT VARIABLES
int mousePos[2] = { 0,0 }; // holds mouse position
enum GAMESTATE { mainMenu, playing, pause }; // gamestate variables as an enum
enum keyEnum{//enumerating directions for readability
	UP,
	DOWN,
	LEFT,
	RIGHT
};
bool keys[] = { UP, DOWN, LEFT, RIGHT };//using those directions

bool mouseButtons[2] = { false, false };//holds the state of left and right mouse buttons

void input();//declares an input function

bool quit = false;//Main loop variable
//END GAME/INPUT VARIABLES



int main(int argc, char* args[]) {
	vector<entity*> entities;//vector holding pouinters to all current entities
	vector<entity*>::iterator entIter;//allows us to iterate through vector
	int currGameState = mainMenu;//sets gamestate to main menu
	SDL_Rect menuRect;
	menuRect.x = 200;
	menuRect.y = 200;
	menuRect.w = 40;
	menuRect.h = 20;


	
								   //Initialize SDL
	if (!window.initialize()) {
		std::cout << "Failed to initialize" << std::endl;
	}

	else {
		renderer = SDL_CreateRenderer(window.window, -1, 0);//sets up the renderer
		
		player sprite(200,200,100,100);//spawns an entity
		sprite.loadSprites("sprite.png", renderer);//loads sprite.png
		button startButton(35, 0, 500, 500);//spawns the (temporary) main menu button
		startButton.loadSprites("play.png", renderer);
		//GAME LOOP////////////////////////////
		while (!quit) {//while the user doesn't exit the game
				
			input();//gets keyboard input and mouse input

				switch (currGameState) {//gamestates are in an enumerated switch statement
				case mainMenu:


					if (startButton.isPressed(mousePos[0], mousePos[1], mouseButtons[0]))//uses the button to switch the gamestate
						currGameState = playing;

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//sets the drawing color of the renderer for clearing and drawing primitives
					SDL_RenderClear(renderer);//clears the screen, prevents smearing


					//SDL_FillRect(window.screenSurface, NULL, SDL_MapRGB(window.screenSurface->format, 0x00, 0x00, 0x00));//colors are in hex rather than base 10, 0x means hex number

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					//SDL_RenderDrawRect(renderer, &menuRect);
					startButton.draw(renderer);
					SDL_RenderPresent(renderer);//goes from memory to the renderer meaning draws contents of renderer
					break;

				case playing:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					sprite.draw(renderer);
					
					SDL_RenderPresent(renderer);
					break;
					}
				}
			//END GAMELOOP///////////////////////
	}

	window.closeSDL();//closes SDL
	return 0;//SDL requires main return something at some point hence the return 0
}//END MAIN////////////////////////////////////////////////////////////////////////////////////////////////////


void input() {
	//Event handler
	SDL_Event event;
	const Uint8* keyboardState;//variable that holds the current keyboard state
	while (SDL_PollEvent(&event) != 0) { // SDL_PollEvent checks(polls) for all events
	if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN) { // if a key is pressed or released
		if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP) { // 
			keys[UP] = true;
		}
		else
			keys[UP] = false;
		if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN) {
			keys[DOWN] = true;
		}
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT) {
			keys[LEFT] = true;
		}
		if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT) {
			keys[RIGHT] = true;
		}
	}
					//User requests quit         
	if (event.type == SDL_QUIT) {//if the button says quit, set quit to true and end the gameloop
		quit = true;
	}
		//INPUT SECTION///////

		if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) { // if there is mouse movement
			SDL_GetMouseState(&mousePos[0], &mousePos[1]); // update the position of the mouse's x and y

			if (event.button.button == SDL_BUTTON_LEFT) // if you click the left button
				mouseButtons[0] = true; // updates mouse button variable
			
			if (event.button.button == SDL_BUTTON_RIGHT)
				mouseButtons[1] = true;
			
		}
	}
}