#include "Camera.h"
#include "Game.h"
#include "Config.h"

void Camera::update() {
	if (game->get_player() != nullptr) {
		Vector playerPosition = game->get_player()->position;
		Vector mouse_position = screenToWorld(Vector(static_cast<float>(engMouseX()), static_cast<float>(engMouseY())));

		Vector target_position = Vector::lerp(playerPosition, mouse_position, 0.3f);

		position = Vector::lerp(position, target_position, CAMERA_SPEED * engDeltaTime());
	}
}

Vector Camera::worldToScreen(Vector vec) {
	return vec - position + Vector(Config::WINDOW_WIDTH/2, Config::WINDOW_HEIGHT /2);
}

Vector Camera::screenToWorld(Vector vec) {
	return vec + position - Vector(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2);
}
