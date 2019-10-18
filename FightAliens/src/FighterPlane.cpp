#include "FighterPlane.h"

FighterPlane::FighterPlane(int x, int y, int dx, SDL_Texture *texture, std::list<Bullet*> *bullets) 
	:BattleObject(x, y, dx, texture, PLAYER),
	m_fire(false),
	m_reload(0),
	m_bltFlying(bullets)
{

}


FighterPlane::~FighterPlane()
{

}

void FighterPlane::update()
{	
	m_dx = m_dy = 0;

	if (m_reload > 0)
	{
		m_reload--;
	}

	if (m_keyboard[SDL_SCANCODE_UP])
	{
		m_dy = -PLAYER_SPEED;
	}

	if (m_keyboard[SDL_SCANCODE_DOWN])
	{
		m_dy = PLAYER_SPEED;
	}

	if (m_keyboard[SDL_SCANCODE_LEFT])
	{
		m_dx = -PLAYER_SPEED;
	}

	if (m_keyboard[SDL_SCANCODE_RIGHT])
	{
		m_dx = PLAYER_SPEED;
	}

	if (m_keyboard[SDL_SCANCODE_SPACE] && m_reload == 0)
	{
		fireBullet();
	}

	m_x += m_dx;
	m_y += m_dy;
}

void FighterPlane::fireBullet(void)
{
	Bullet *bullet = new Bullet(m_x, m_y, PLAYER_BULLET_SPEED, m_h, m_BulletTexture, PLAYER);

	m_bltFlying->push_back(bullet);

	m_reload = 8;
}

void FighterPlane::setPressKeyValue(SDL_Scancode scanCode, int value)
{
	m_keyboard[scanCode] = value;
}

void FighterPlane::setBulletTexture(SDL_Texture * texture)
{
	m_BulletTexture = texture;
}