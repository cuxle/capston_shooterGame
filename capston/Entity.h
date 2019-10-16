#pragma once
#include "SDL.h"

enum SIDE_PLAYER {
	PLAYER,
	ALIEN
};

class Entity
{
public:
	Entity(int x, int y, SIDE_PLAYER side);
	virtual ~Entity();
	virtual void update();
	bool isFriend(Entity *side);
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
	bool health;
	SDL_Texture *m_texture;
	SIDE_PLAYER m_side;
};

