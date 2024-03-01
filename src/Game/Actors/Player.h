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

	bool isInvicible() {
		return engTimePassedSince(lastHitTime) < INVINCIBILITY_TIME;
	}

	int health = 3;
	float lastHitTime = 0.f;
};

