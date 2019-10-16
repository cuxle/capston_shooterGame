#include "Bullet.h"
#include <iostream>
#include "defs.h"


Bullet::Bullet(int x, int y, SIDE_PLAYER side) :
	Entity(x, y, side)
{

}

Bullet::~Bullet()
{

}

void Bullet::update()
{
	m_x += m_dx;
	m_y += m_dy;
}

bool Bullet::isOutOfBoarder()
{
	return m_x > SCREEN_WIDTH;
}
