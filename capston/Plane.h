#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <list>

class Plane :
	public Entity
{
public:
	Plane(int x, int y, SIDE_PLAYER side);
	~Plane();
	static std::list<Bullet*> m_bltFlying;
};


