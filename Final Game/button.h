#include<SDL.h>
#include"entity.h"
#pragma once
class button : public entity //for cliking a buton and doing stuff
{
private:
	bool buttonPressed = false;//holds if the button instance is pressed

public:
	bool isPressed(int x, int y, bool LmouseButtonState);//determines if button is clicked from mouse information
	button(int x, int y, int w, int h);//constructor, you pass it the position of the button and the size of the button
};