#include "Bullet.h"

Bullet::Bullet(Vector position, Vector direction) 
	: Actor(position, Vector(4.f), COLOR_YELLOW) , direction(direction){
	this->direction.normalize();
	collisionChannel = CollisionChannel::Bullet;
	spawnTime = engCurrentTime();
}

void Bullet::update() {
	position += direction * SPEED * engDeltaTime();

	Actor* hitActor = game->getCollidingActor(this, CollisionChannel::Enemy);

	if (hitActor != nullptr) {
		hitActor->hit(DAMAGE);
		destroy();
	}

	if (engTimePassedSince(spawnTime) > LIFETIME) {
		destroy();
	}
}
