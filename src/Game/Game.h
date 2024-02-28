#pragma once
#include "Actor.h"
#include "Components/InputComponent.h"
#include "Actors/Player.h"
#include "Actors/Enemy.h"



#define MAX_ACTORS 20


class Game
{
public:
	Game() = default;

	void initGame();
	void gameLoop();

	Actor* get_player() { return player; }

	void spawn_actor(Actor* actor);

	Actor* getCollidingActor(Actor* other, CollisionChannel collisionChannel);

private:
	void update();
	void render();

	static constexpr float SPAWN_INTERVAL = .5f;

	Actor* actors[MAX_ACTORS] = { nullptr };
	Actor* player = nullptr;

	float player_speed = 100.f;
	float lastSpawnTime = .0f;
};

extern Game* game;

