#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(int x, int y, SIDE_PLAYER side);
	~Bullet();
	bool isHealthy() const {
		return health;
	}

	void setHealthy(int h) {
		health = h;
	}
};

