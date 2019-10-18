#pragma once
#include "SDL.h"
#include <vector>
#include <string>
#include "BattleObject.h"

class Renderer
{
public:
	Renderer(const std::size_t screen_width, const std::size_t screen_height);
	~Renderer();
	void UpdateWindowTitle(int score, int fps);
	void prepareScene(void);
	void presentScene(void);
	SDL_Texture *loadTexture(const char * pathName);
	void blit(BattleObject *object);
private:
	SDL_Window *sdl_window;
	SDL_Renderer *sdl_renderer;

	const std::size_t screen_width;
	const std::size_t screen_height;
};

