#include "Game.h"
#include <Math/AABB.h>
#include "Actors/Pickup.h"

Game* game = nullptr;
constexpr float PI = 3.14f;

void spawnPickup() {
	float angle = engRandomF() * PI;
	Vector offset = Vector(cosf(angle), sinf(angle)) * 300.f;

	game->spawn_actor(new Pickup(Vector(game->get_player()->position + offset)));
}

void spawnEnemy() {
	if (Enemy::NUM_ENEMIES < game->MAX_NUM_ENEMIES) {
		float angle = engRandomF() * PI;
		Vector offset = Vector(cosf(angle), sinf(angle)) * 700.f;

		game->spawn_actor(new Enemy(Vector(game->get_player()->position + offset)));
		//game->timers.addTimer(SPAWN_INTERVAL, &spawnEnemy);
	}
}

void Game::initGame() {
	actors[0] = new Player(Vector(100.f, 100.f));
	player = actors[0];

	timers.addTimer(SPAWN_INTERVAL, true, &spawnEnemy);
	timers.addTimer(PICKUP_INTERVAL, true, &spawnPickup);
}

void Game::gameLoop() {
	while (engBeginFrame()) {
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		if (engKeyPressed(Key::Escape))
		{
			return;
		}

		update();
		render();
	}
}

void Game::spawn_actor(Actor* actor) {
	for (int i = 0; i < MAX_ACTORS; ++i) {
		if (actors[i] == nullptr) {
			actors[i] = actor;
			break;
		}
	}
}

Actor* Game::getCollidingActor(Actor* other, CollisionChannel channel)
{
	for (int i = 0; i < MAX_ACTORS; ++i) {
		if (actors[i] != other && actors[i] != nullptr && actors[i]->collisionChannel == channel) {
			AABB a = AABB::fromPositionSize(other->position, other->size);
			AABB b = AABB::fromPositionSize(actors[i]->position, actors[i]->size);

			if (AABB::aabbOverlap(a, b)) {
				return actors[i];
			}
		}
	}
	return nullptr;
}

void Game::update() {
	timers.update();

	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->update();

			if (actors[i]->getIsDestroyed()) {
				if (actors[i] == player) {
					player = nullptr;
				}
				delete actors[i];
				actors[i] = nullptr;
			}
		}

	}
	camera.update();
}

void Game::render() {
	// Draw background
	for (int x = -50; x <= 50; ++x)
	{
		for (int y = -50; y <= 50; ++y)
		{
			if ((x + y) % 2 == 0)
				engSetDrawColor(0x120D0FFF);
			else
				engSetDrawColor(0x21181BFF);

			Vector position = Vector(x * GRID_SIZE, y * GRID_SIZE);
			position = camera.worldToScreen(position);

			engFillRect((int)position.x, (int)position.y, (int)GRID_SIZE, (int)GRID_SIZE);
		}
	}
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->render();
		}
	}
}
