#include "AlienPlane.h"
#include <iostream>

int AlienPlane::m_SpawnTimer = 0;

AlienPlane::AlienPlane(int x, int y):
	Entity(x,y, ALIEN)
{

}


AlienPlane::~AlienPlane()
{
	std::cout << "alien plane destorying................." << std::endl;
}

void AlienPlane::update()
{
	m_x += m_dx;
	m_y += m_dy;
}
