#include <iostream>
#include "SDL.h"
#include "renderer.h"
#include "controller.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
	constexpr std::size_t kFramesPerSecond{ 60 };
	constexpr std::size_t kMsPerFrame{ 1000 / kFramesPerSecond };
	constexpr std::size_t kScreenWidth{ 1280 };
	constexpr std::size_t kScreenHeight{ 720 };
	constexpr std::size_t kGridWidth{ 32 };
	constexpr std::size_t kGridHeight{ 32 };

	Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
	Controller controller;
	Game game(kGridWidth, kGridHeight);
	game.Run(controller, renderer, kMsPerFrame);

	std::cout << "Game has terminated successfully!\n";
	std::cout << "Score: " << game.GetScore() << "\n";

	return 0;
}