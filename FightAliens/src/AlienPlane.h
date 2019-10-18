#pragma once
#include "BattleObject.h"
class AlienPlane :	public BattleObject
{
public:
	AlienPlane(int x, int y, int speed, SDL_Texture * texture);
	virtual ~AlienPlane();
	virtual void update();
	static int m_SpawnTimer;
private:
	int m_traveledLength;
};

//

