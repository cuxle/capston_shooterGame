#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(int x, int y, SIDE_PLAYER side);
	~Bullet();
	virtual void update();

	bool isOutOfBoarder();

	bool isHealthy() const {
		return health;
	}

	void setHealthy(int h) {
		health = h;
	}
};

