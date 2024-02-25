#include "Enemy.h"

void Enemy::update() {
	Vector direction = game.get_player()->position - position;
	direction.normalize();

	position += direction * speed * engDeltaTime();
}
