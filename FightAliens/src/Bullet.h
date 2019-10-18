#pragma once
#include "BattleObject.h"
class Bullet : public BattleObject
{
public:
	Bullet(int x, int y, int speed, int dadHeight, SDL_Texture * texture, SIDE_PLAYER side);
	~Bullet();
	virtual void update();
	bool isOutOfBoarder();

private:
	int m_traveledLength;
};

