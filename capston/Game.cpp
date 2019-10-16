#include "Game.h"
#include "AlienPlane.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

Game::Game(std::size_t grid_width, std::size_t grid_height)
	:m_player(new FighterPlane(100, 100)),
	m_bullets(Plane::m_bltFlying)
{

}
void Game::Run(Controller &controller, Renderer &renderer,
	std::size_t target_frame_duration) 
{
	Uint32 title_timestamp = SDL_GetTicks();
	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int frame_count = 0;
	bool running = true;	

	//init textures
	m_PlayerTexture = renderer.loadTexture("gfx/player.png");
	m_PlayerBulletTexture = renderer.loadTexture("gfx/playerBullet.png");
	m_EnemyTexture = renderer.loadTexture("gfx/enemy.png");

	//init player
	m_player->m_texture = m_PlayerTexture;
	m_player->setBulletTexture(m_PlayerBulletTexture);
	SDL_QueryTexture(m_PlayerTexture, NULL, NULL, &m_player->m_w, &m_player->m_h);
	
	m_fighters.push_back(m_player);


	while (running) {
		frame_start = SDL_GetTicks();

		//1. renderer:prepareScene renderer
		renderer.prepareScene();

		//2. controller: handleInput
		controller.HandleInput(running, *m_player);

		//2.1 update 
		Update();

		//3 render fighters
		for (auto fighter : m_fighters) {
			renderer.blit(fighter);
		}

		for (auto iter = m_player->m_bltFlying.begin(); iter != m_player->m_bltFlying.end(); iter++) {
			renderer.blit(*iter);
		}

		//3. presentScene
		renderer.presentScene();

		//4. process the 60 frame per second
		frame_end = SDL_GetTicks();
		frame_count++;
		frame_duration = frame_end - frame_start;

		// After every second, update the window title.
		if (frame_end - title_timestamp >= 1000) {
			renderer.UpdateWindowTitle(m_score, frame_count);
			frame_count = 0;
			title_timestamp = frame_end;
		}

		// If the time for this frame is too small (i.e. frame_duration is
		// smaller than the target ms_per_frame), delay the loop to
		// achieve the correct frame rate.
		if (frame_duration < target_frame_duration) {
			SDL_Delay(target_frame_duration - frame_duration);
		}
	}
}

Game::~Game()
{
	if (m_player) {
		delete m_player;
		m_player = nullptr;
	}

	for (auto item : m_fighters) {
		if (item) {
			delete item;
		}
	}
}

int Game::GetScore() const
{
	return m_score;
}

void Game::Update()
{
	dofighters();
	doBullets();
	spawnEnemies();
}

void Game::doBullets()
{
	auto iter = m_bullets.begin();
	while (iter != m_bullets.end()) {
		Bullet *bullet = *iter;
		bullet->update();
		if (bulletHitFighter(bullet) || bullet->isOutOfBoarder()) {
			delete bullet;
			iter = m_bullets.erase(iter);
		}
		else {
			iter++;
		}
	}
}

void Game::dofighters()
{
	auto iter = m_fighters.begin();
	while (iter != m_fighters.end()) {
		(*iter)->update();

		if (((*iter) != m_player) && (((*iter)->m_x <= 4) || ((*iter)->health == 0))) {
			delete *iter;
			iter = m_fighters.erase(iter);
		}
		else {
			iter++;
		}
	}
}

void Game::spawnEnemies()
{
	if (--AlienPlane::m_SpawnTimer <= 0) {

		AlienPlane *enemy = new AlienPlane(SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
		enemy->m_texture = m_EnemyTexture;
		enemy->m_dx = -(2 + (rand() % 4));
		enemy->health = 1;

		SDL_QueryTexture(enemy->m_texture, NULL, NULL, &enemy->m_w, &enemy->m_h);

		AlienPlane::m_SpawnTimer = 30 + (rand() % 60);

		m_fighters.push_back(enemy);
	}
}

int Game::collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (MAX(x1, x2) < MIN(x1 + w1, x2 + w2)) && (MAX(y1, y2) < MIN(y1 + h1, y2 + h2));
}

bool Game::bulletHitFighter(Entity *bullet)
{
	for (auto fighter : m_fighters) {
		if (!fighter->isFriend(bullet) && collision(bullet->m_x, bullet->m_y, bullet->m_w, bullet->m_h, fighter->m_x, fighter->m_y, fighter->m_w, fighter->m_h)) {
			bullet->health = 0;
			fighter->health = 0;
			m_score++;
			return true;
		}
	}
	return false;
}