#include <iostream>
#include "SDL.h"
#include "Renderer.h"
#include "Controller.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
	constexpr std::size_t kFramesPerSecond{ 60 };
	constexpr std::size_t kMsPerFrame{ 1000 / kFramesPerSecond };
	constexpr std::size_t kScreenWidth{ 1280 };
	constexpr std::size_t kScreenHeight{ 720 };

	Renderer renderer(kScreenWidth, kScreenHeight);
	Controller controller;
	Game game;
	game.Run(controller, renderer, kMsPerFrame);

	std::cout << "Game has terminated successfully!\n";
	std::cout << "Score: " << game.GetScore() << "\n";

	return 0;
}