#include "AlienPlane.h"
#include <iostream>
#include "defs.h"

int AlienPlane::m_SpawnTimer = 0;

AlienPlane::AlienPlane(int x, int y, int speed, SDL_Texture * texture) :
	BattleObject(x, y, speed, texture, ALIEN),
	m_traveledLength(0)
{

}


AlienPlane::~AlienPlane()
{

}

void AlienPlane::update()
{
	m_x += m_dx;
	m_y += m_dy;
	m_traveledLength += m_dx;
	if (m_traveledLength > SCREEN_WIDTH) {
		setDead();
	}
}
