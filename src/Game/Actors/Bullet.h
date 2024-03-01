#pragma once
#include "Game/Actor.h"
#include "Game/Game.h"

class Bullet : public Actor {
public:
	Bullet(Vector position, Vector direction);
	void update() override;

private:
	static constexpr float SPEED = 1000.f;
	static constexpr float LIFETIME = 1.f;
	static constexpr int DAMAGE = 40;

	Vector direction;
	float spawnTime;
};

