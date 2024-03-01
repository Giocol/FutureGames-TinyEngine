#include "Enemy.h"

int Enemy::NUM_ENEMIES = 0;

Enemy::Enemy(Vector position) 
	: Actor(position, Vector(20.f, 20.f), COLOR_RED) {
	collisionChannel = CollisionChannel::Enemy; 
NUM_ENEMIES++; 
}


Enemy::~Enemy() {
	NUM_ENEMIES--;
}

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

void Enemy::render() {
	if (health < MAX_HEALTH) {
		float healthPercentage = static_cast<float>(health) / static_cast<float>(MAX_HEALTH);
		Vector screenPosition = game->get_camera().worldToScreen(position);

		engSetDrawColor(COLOR_LIGHT_GRAY);
		engFillRect(static_cast<int>(screenPosition.x - 26), static_cast<int>(screenPosition.y - 32), 26 * 2, 8);
		engSetDrawColor(COLOR_RED);
		engFillRect(static_cast<int>(screenPosition.x - 26), static_cast<int>(screenPosition.y - 32), static_cast<int>(26.f * 2.f * healthPercentage), 8);
	}
	Actor::render();
}

void Enemy::hit(int damage) {
	health -= damage;
	if (health <= 0) {
		destroy();
	}
}
