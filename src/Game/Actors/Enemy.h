#pragma once
#include "Game/Actor.h"
#include "Game/Game.h"

class Enemy : public Actor {
public:
	static int NUM_ENEMIES; 

	Enemy(Vector position);;
	~Enemy();
	
	void update() override;
	void render() override;

	void hit(int damage);

	float speed = 50.f;
private:
	int attackDamage = 1;
	static constexpr int MAX_HEALTH = 100;
	int health = MAX_HEALTH;
};

