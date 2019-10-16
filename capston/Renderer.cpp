#include "Renderer.h"
#include <iostream>
#include <string>
#include "SDL_image.h"

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height,
	const std::size_t grid_width, const std::size_t grid_height)
	:screen_width(screen_width),
	screen_height(screen_height),
	grid_width(grid_width),
	grid_height(grid_height)
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize.\n";
		std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
	}

	// Create Window
	sdl_window = SDL_CreateWindow("Shooter Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screen_width,
		screen_height, SDL_WINDOW_SHOWN);

	if (nullptr == sdl_window) {
		std::cerr << "Window could not be created.\n";
		std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	// Create renderer
	sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
	if (nullptr == sdl_renderer) {
		std::cerr << "Renderer could not be created.\n";
		std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
	}

	int flags = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	if (flags & IMG_INIT_PNG || flags & IMG_INIT_JPG) {
		std::cout << "could not initialize sdl2_image:" << IMG_GetError() << std::endl;
		//fprintf(stderr, "could not initialize sdl2_image: %s\n", IMG_GetError());
	}
	else {
		std::cout << "image init successfully!" << std::endl;
	}
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}

void Renderer::Render(BattleField const &bfield)
{
	//do renderer all the fields in the field
	//do players
	//do fighters
	//do bullets
	//do fighters
	//do enmeies
}


void Renderer::UpdateWindowTitle(int score, int fps)
{
	std::string title{ "Player Score: " + std::to_string(score) + " FPS: " + std::to_string(fps) };
	SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::prepareScene(void)
{
	SDL_SetRenderDrawColor(sdl_renderer, 32, 32, 32, 255);
	SDL_RenderClear(sdl_renderer);
}


void Renderer::presentScene(void)
{
	SDL_RenderPresent(sdl_renderer);
}

SDL_Texture *Renderer::loadTexture(const char * pathName)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", pathName);

	texture = IMG_LoadTexture(sdl_renderer, pathName);

	return texture;
}


void Renderer::blit(Entity *entity)
{
	SDL_Rect dest;

	dest.x = entity->m_x;
	dest.y = entity->m_y;
	SDL_QueryTexture(entity->m_texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(sdl_renderer, entity->m_texture, NULL, &dest);
}