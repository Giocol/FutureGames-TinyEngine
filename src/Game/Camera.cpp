#include "Camera.h"
#include "Game.h"
#include "Config.h"

void Camera::update() {
	if (game->get_player() != nullptr) {
		position = game->get_player()->position;
	}
}

Vector Camera::worldToScreen(Vector vec) {
	return vec - position + Vector(Config::WINDOW_WIDTH/2, Config::WINDOW_HEIGHT /2);
}

Vector Camera::screenToWorld(Vector vec) {
	return vec + position - Vector(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2);
}
