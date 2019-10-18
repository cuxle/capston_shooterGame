#include "BattleObject.h"
#include <iostream>

BattleObject::BattleObject(int x, int y, int speed, SDL_Texture *texture, SIDE_PLAYER side)
	:m_x(x),
	m_y(y),	
	m_dx(speed),
	m_dy(0),
	m_health(ALIVE),
	m_texture(texture),
	m_side(side)
{
	SDL_QueryTexture(m_texture, NULL, NULL, &m_w, &m_h);
}

BattleObject::~BattleObject()
{

}

bool BattleObject::isFriend(BattleObject *ety)
{
	return m_side == ety->m_side;
}

void BattleObject::setDead(void)
{
	m_health = DEAD;
}

bool BattleObject::isAlive(void) const
{
	return m_health == ALIVE;
}