#pragma once
#include "Game/Actor.h"
#include "Game/Game.h"

class Enemy : public Actor {
public:
	Enemy(Vector position) : Actor(position, Vector(20.f, 20.f), COLOR_RED) {};
	void update() override;

	float speed = 50.f;
};

