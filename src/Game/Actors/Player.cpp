#include "Player.h"

void Player::update() {
	input_tick(position, speed);
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

	Actor::render();
}
