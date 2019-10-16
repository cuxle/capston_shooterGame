#pragma once
#include "Entity.h"
#include "Plane.h"
#include "Bullet.h"
#include "defs.h"
#include <iostream>
#include <list>

class FighterPlane : public Plane
{
public:
	FighterPlane(int x, int y);
	~FighterPlane();
	virtual void update();
	void updateBullets();
	void updatePlayer();
	Bullet *m_bullet;
	bool m_fire;
	int keyboard[MAX_KEYBOARD_KEYS];
	int m_reload;
	void fireBullet(void);	
};

