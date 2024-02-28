#include "Game.h"
#include <Math/AABB.h>

Game* game = nullptr;

void Game::initGame() {
	actors[0] = new Player(Vector(100.f, 100.f));
	player = actors[0];

	actors[1] = new Enemy(Vector(600.f, 250.f));
	actors[2] = new Enemy(Vector(300.f, 250.f));

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
	if (engTimePassedSince(lastSpawnTime) > SPAWN_INTERVAL) {
		spawn_actor(new Enemy(Vector(static_cast<float>(engRandom(0, 800)), static_cast<float>(engRandom(0, 600)))));
		lastSpawnTime = engCurrentTime();
	}

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
}

void Game::render() {
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->render();
		}
	}
}
