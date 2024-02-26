#pragma once
#include "Game/Actor.h"
#include "Game/Game.h"

class Bullet : public Actor {
public:
	Bullet(Vector position, Vector direction);
	void update() override;

private:
	Vector direction;
};

