#include "Controller.h"
#include "SDL.h"
#include "entity.h"
#include "defs.h"

void Controller::doKeyUp(SDL_KeyboardEvent *event, FighterPlane &player)
{
	if (event->repeat == 0 && (event->keysym.scancode < MAX_KEYBOARD_KEYS))
	{
		player.keyboard[event->keysym.scancode] = 0;
	}
}

void Controller::doKeyDown(SDL_KeyboardEvent *event, FighterPlane &player)
{
	if (event->repeat == 0 && (event->keysym.scancode < MAX_KEYBOARD_KEYS))
	{
		player.keyboard[event->keysym.scancode] = 1;
	}
}


void Controller::HandleInput(bool &running, FighterPlane &player)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			doKeyDown(&e.key, player);
			break;

		case SDL_KEYUP:
			doKeyUp(&e.key, player);
			break;

		default:
			break;
		}
	}
}