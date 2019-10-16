#pragma once

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "entity.h"
#include "FighterPlane.h"
#include "AlienPlane.h"
#include "plane.h"

class Game
{
public:
	Game(std::size_t grid_width, std::size_t grid_height);
	~Game();
	void Run(Controller  &controller, Renderer &renderer,
		std::size_t target_frame_duration);
	int GetScore() const;

private:
	FighterPlane *m_player;
	AlienPlane m_enemy;
	std::list<Entity*> m_fighters;
	std::list<Bullet*> &m_bullets;
	std::random_device dev;
	std::mt19937 engine;
	std::uniform_int_distribution<int> random_w;
	std::uniform_int_distribution<int> random_h;

	int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	bool bulletHitFighter(Entity *b);
	int score{ 0 };
	void Update();
	void doPlayer();
	void doBullets();
	void dofighters();
	void spawnEnemies();
	friend class Renderer;
};

