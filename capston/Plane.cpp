#include "Plane.h"

std::list<Bullet*> Plane::m_bltFlying;

Plane::Plane(int x, int y, SIDE_PLAYER side) :
	Entity(x, y, side)
{

}


Plane::~Plane()
{

}
