#include "Player.h"

void Player::update() {
	input_tick(position, speed);
}

void Player::render() {
	engSetDrawColor(COLOR_RED);
	engDrawLine(static_cast<int>(position.x), static_cast<int>(position.y), engMouseX(), engMouseY());

	Actor::render();
}
