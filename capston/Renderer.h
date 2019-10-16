#pragma once
#include "SDL.h"
#include "battlefield.h"
#include <vector>
#include <string>
#include "entity.h"

class Renderer
{
public:
	Renderer(const std::size_t screen_width, const std::size_t screen_height,
		const std::size_t grid_width, const std::size_t grid_height);
	~Renderer();

	void Render(BattleField const &bfield);
	void UpdateWindowTitle(int score, int fps);
	void prepareScene(void);
	void presentScene(void);
	SDL_Texture *loadTexture(const char * pathName);
	void blit(Entity *entity);
private:
	SDL_Window *sdl_window;
	SDL_Renderer *sdl_renderer;

	const std::size_t screen_width;
	const std::size_t screen_height;
	const std::size_t grid_width;
	const std::size_t grid_height;
};

