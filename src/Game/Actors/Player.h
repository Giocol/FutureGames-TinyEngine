#pragma once
#include "../Actor.h"
#include "../Components/InputComponent.h"

class Player :public Actor {
public:
	Player(Vector position) : Actor(position, Vector(32), COLOR_WHITE) {};

	void update() override;
	float speed = 100.f;
};

