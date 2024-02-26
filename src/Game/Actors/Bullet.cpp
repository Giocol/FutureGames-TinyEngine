#include "Bullet.h"

Bullet::Bullet(Vector position, Vector direction) 
	: Actor(position, Vector(4.f), COLOR_YELLOW) , direction(direction){
	this->direction.normalize();
}

void Bullet::update() {
	position += direction * 1000.f * engDeltaTime();
}
