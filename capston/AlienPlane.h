#pragma once
#include "Entity.h"
class AlienPlane :	public Entity
{
public:
	AlienPlane(int x, int y);
	virtual ~AlienPlane();
	virtual void update();
	static int m_SpawnTimer;
};

//

