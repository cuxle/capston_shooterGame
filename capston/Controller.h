#pragma once

#include "fighterplane.h"
#include "SDL.h"

class Controller
{
public:
	void HandleInput(bool &running, FighterPlane &player);
	void doKeyDown(SDL_KeyboardEvent *event, FighterPlane &player);
	void doKeyUp(SDL_KeyboardEvent *event, FighterPlane &player);
private:
};

