#pragma once

#include <random>
#include "SDL.h"
#include "Controller.h"
#include "Renderer.h"
#include "BattleObject.h"
#include "FighterPlane.h"
#include "AlienPlane.h"

class Game
{
public:
	Game();
	~Game();
	void Run(Controller  &controller, Renderer &renderer,
		std::size_t target_frame_duration);
	int GetScore() const;

private:
	FighterPlane *m_player;

	std::list<BattleObject*> m_fighters;
	std::list<Bullet*> m_bullets;
	std::random_device dev;
	std::mt19937 engine;
	std::uniform_int_distribution<int> random_w;
	std::uniform_int_distribution<int> random_h;

	int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	bool bulletHitFighter(BattleObject *b);
	int m_score{ 0 };
	void Update();
	void doPlayer();
	void doBullets();
	void dofighters();
	void spawnEnemies();
	SDL_Texture *m_PlayerBulletTexture;
	SDL_Texture *m_EnemyBulletTexture;
	SDL_Texture *m_PlayerTexture;
	SDL_Texture *m_EnemyTexture;
	friend class Renderer;
};
