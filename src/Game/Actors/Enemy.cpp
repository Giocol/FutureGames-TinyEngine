#include "Enemy.h"

void Enemy::update() {
	if (game->get_player() != nullptr) {
		Vector direction = game->get_player()->position - position;
		direction.normalize();

		position += direction * speed * engDeltaTime();

		Actor* hitActor = game->getCollidingActor(this, CollisionChannel::Player);

		if (hitActor != nullptr) {
			hitActor->hit(attackDamage);
		}
	}
}
