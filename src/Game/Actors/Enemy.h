#pragma once
#include "Game/Actor.h"
#include "Game/Game.h"

class Enemy : public Actor {
public:
	Enemy(Vector position) : Actor(position, Vector(20.f, 20.f), COLOR_RED) { collisionChannel = CollisionChannel::Enemy;  };
	void update() override;
	void render() override;

	void hit(int damage) {
		health -= damage;
		if (health <= 0) {
			destroy();
		}
	}

	float speed = 50.f;
private:
	int attackDamage = 1;
	static constexpr int MAX_HEALTH = 100;
	int health = MAX_HEALTH;
};

