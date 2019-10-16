#include "FighterPlane.h"



FighterPlane::FighterPlane(int x, int y) :
	Plane(x, y, PLAYER),
	m_bullet(new Bullet(x, y, PLAYER)),
	m_fire(false),
	m_reload(0)
{

}


FighterPlane::~FighterPlane()
{
}

void FighterPlane::update()
{	
	updatePlayer();

}

void FighterPlane::updatePlayer()
{
	m_dx = m_dy = 0;

	if (m_reload > 0)
	{
		m_reload--;
	}

	if (keyboard[SDL_SCANCODE_UP])
	{
		m_dy = -PLAYER_SPEED;
	}

	if (keyboard[SDL_SCANCODE_DOWN])
	{
		m_dy = PLAYER_SPEED;
	}

	if (keyboard[SDL_SCANCODE_LEFT])
	{
		m_dx = -PLAYER_SPEED;
	}

	if (keyboard[SDL_SCANCODE_RIGHT])
	{
		m_dx = PLAYER_SPEED;
	}

	if (keyboard[SDL_SCANCODE_SPACE] && m_reload == 0)
	{
		fireBullet();
	}

	m_x += m_dx;
	m_y += m_dy;
}

void FighterPlane::fireBullet(void)
{
	Bullet *bullet = new Bullet(m_x, m_y, PLAYER);
	m_bltFlying.push_back(bullet);

	bullet->m_dx = PLAYER_BULLET_SPEED;
	bullet->setHealthy(1);

	bullet->m_texture = m_bullet->m_texture;
	SDL_QueryTexture(bullet->m_texture, NULL, NULL, &bullet->m_w, &bullet->m_h);

	bullet->m_y += (m_h / 2) - (bullet->m_h / 2);

	m_reload = 8;

	std::cout << "m_bltFlying size:" << m_bltFlying.size() << std::endl;
}

void FighterPlane::updateBullets()
{
	auto iter = m_bltFlying.begin();
	while (iter != m_bltFlying.end()) {
		(*iter)->m_x += (*iter)->m_dx;
		(*iter)->m_y += (*iter)->m_dy;

 		if ((*iter)->m_x > SCREEN_WIDTH) {
			delete *iter;
			iter = m_bltFlying.erase(iter);
		}
		else {
			iter++;
		}
	}

}