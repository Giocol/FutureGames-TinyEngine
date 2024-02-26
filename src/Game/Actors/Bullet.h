#pragma once
#include "Game/Actor.h"

class Bullet : public Actor {
public:
	Bullet(Vector position, Vector direction);
	void update() override;

private:
	Vector direction;
};

