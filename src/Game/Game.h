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

private:
	void update();
	void render();

	Actor* actors[MAX_ACTORS] = { nullptr };
	Actor* player = nullptr;

	float player_speed = 100.f;
};

extern Game game;

