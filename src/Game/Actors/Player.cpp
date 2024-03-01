#include "Player.h"

void Player::update() {
	input_tick(position, speed);
	Actor* pickupActor = game->getCollidingActor(this, CollisionChannel::Pickup);
	if (pickupActor && health < MAX_HEALTH) {
		pickupActor->destroy();
		health++;
	}
}

void Player::render() {

	Vector mouse_position = Vector(static_cast<float>(engMouseX()), static_cast<float>(engMouseY()));
	mouse_position = game->get_camera().screenToWorld(mouse_position);

	Vector aim_direction = mouse_position - position;
	aim_direction.normalize();

	Vector crosshair_start = game->get_camera().worldToScreen(position + aim_direction * 45.f);
	Vector crosshair_end = game->get_camera().worldToScreen(position + aim_direction * 5000.f);

	engSetDrawColor(COLOR_RED);
	engDrawLine(
		(int)crosshair_start.x, (int)crosshair_start.y,
		(int)crosshair_end.x, (int)crosshair_end.y
	);

	//Render health UI
	for (int i = 0; i < MAX_HEALTH; i++) {
		if (i < health) {
			engSetDrawColor(COLOR_WHITE);
		}
		else {
			engSetDrawColor(0xFFFFFF55);
		}
		engFillRect(10 + 40 * i, 10, 32, 32);
	}
	
	//flash player when invicnible
	if (isInvicible()) {
		if (static_cast<int>(engCurrentTime() * 5) % 2 == 0) {
			color = 0xFFFFFF77;
		}
		else {
			color = COLOR_WHITE;
		}
	}
	else {
		color = COLOR_WHITE;
	}

	Actor::render();
}

void Player::hit(int damage) {
	if (!isInvicible()) {
		health -= damage;
		
		lastHitTime = engCurrentTime();

		if (health <= 0) {
			destroy();
		}
	}
}
