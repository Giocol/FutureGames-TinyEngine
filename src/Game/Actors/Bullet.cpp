#include "Bullet.h"

Bullet::Bullet(Vector position, Vector direction) 
	: Actor(position, Vector(4.f), COLOR_YELLOW) , direction(direction){
	this->direction.normalize();
	collisionChannel = CollisionChannel::Bullet;
	spawnTime = engCurrentTime();
}

void Bullet::update() {
	position += direction * 1000.f * engDeltaTime();

	Actor* hitActor = game.getCollidingActor(this, CollisionChannel::Enemy);

	if (hitActor != nullptr) {
		hitActor->destroy();
		destroy();
	}

	if (engTimePassedSince(spawnTime) > BULLET_LIFETIME) {
		destroy();
	}
}
