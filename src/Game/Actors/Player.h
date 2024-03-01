#pragma once
#include "Game/Actor.h"
#include "Game/Components/InputComponent.h"

class Player :public Actor {
public:
	Player(Vector position) : Actor(position, Vector(32), COLOR_WHITE) { collisionChannel = CollisionChannel::Player; };

	void update() override;
	void render() override;

	void hit(int damage) override;

	float speed = 300.f;
private:
	static constexpr float INVINCIBILITY_TIME = 2.f;
	static constexpr int MAX_HEALTH = 3;

	bool isInvicible() {
		return engTimePassedSince(lastHitTime) < INVINCIBILITY_TIME;
	}

	int health = MAX_HEALTH;
	float lastHitTime = -INVINCIBILITY_TIME;
};

