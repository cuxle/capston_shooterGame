#pragma once
#include "BattleObject.h"
#include "Bullet.h"
#include "defs.h"
#include <iostream>
#include <list>
#include "SDL.h"

class FighterPlane : public BattleObject
{
public:
	FighterPlane(int x, int y, int dx, SDL_Texture *texture, std::list<Bullet*> *bullets);
	~FighterPlane();

	virtual void update();
	void setPressKeyValue(SDL_Scancode scanCode, int value);
	void setBulletTexture(SDL_Texture *texTure);
private:
	void fireBullet(void);	
	void updatePlayer();

	bool m_fire;
	int m_keyboard[MAX_KEYBOARD_KEYS] = {0};
	int m_reload;
	SDL_Texture *m_BulletTexture;
	std::list<Bullet*> *m_bltFlying;	
};

