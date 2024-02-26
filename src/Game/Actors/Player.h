#pragma once
#include "Game/Actor.h"
#include "Game/Components/InputComponent.h"

class Player :public Actor {
public:
	Player(Vector position) : Actor(position, Vector(32), COLOR_WHITE) {};

	void update() override;
	float speed = 100.f;
};

