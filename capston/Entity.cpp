#include "entity.h"

Entity::Entity(int x, int y, SIDE_PLAYER side)
	:m_x(x),
	m_y(y),
	m_side(side)
{

}

Entity::~Entity()
{

}

void Entity::update()
{
	//1. update position
	if (m_up)
	{
		m_y -= 4;
	}

	if (m_down)
	{
		m_y += 4;
	}

	if (m_left)
	{
		m_x -= 4;
	}

	if (m_right)
	{
		m_x += 4;
	}
	//2. update fire
}
