#include "Bullet.h"
#include <iostream>
#include "defs.h"

Bullet::Bullet(int x, int y, int speed, int fighterHeight, SDL_Texture * texture, SIDE_PLAYER side) 
	: BattleObject(x, y, speed, texture, side),
	m_traveledLength(0)
{
	m_y += (fighterHeight / 2) - (m_h / 2);
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
	m_x += m_dx;
	m_y += m_dy;
	m_traveledLength += m_dx;
	if (isOutOfBoarder()) {
		setDead();
	}
}

bool Bullet::isOutOfBoarder()
{
	return m_traveledLength > SCREEN_WIDTH;
}
