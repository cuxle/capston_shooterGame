#pragma once
#include "SDL.h"

enum SIDE_PLAYER {
	PLAYER,
	ALIEN
};

enum HEALTH_STATE {
	ALIVE,
	DEAD
};

class BattleObject
{
public:
	BattleObject(int x, int y, int speed, SDL_Texture *texture, SIDE_PLAYER side);
	virtual ~BattleObject();
	
	bool isFriend(BattleObject *side);
	void setDead();

	//player,bullet and enemy dies at different condition
	virtual void update() = 0;
	bool virtual isAlive() const;

	int m_x;
	int m_y;
	int m_up;
	int m_down;
	int m_left;
	int m_right;
	int m_dx;
	int m_dy;
	int m_w;
	int m_h;
	HEALTH_STATE m_health;
	SDL_Texture *m_texture;
	SIDE_PLAYER m_side;
};

