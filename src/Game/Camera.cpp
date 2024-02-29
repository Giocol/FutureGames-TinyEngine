#include "Camera.h"
#include <Engine/TinyEngine.h>
#include "Actors/Player.h"

void Camera::update() {
	Vector player_position = player->position;
	Vector mouse_position = screenToWorld(Vector(static_cast<float>(engMouseX()), static_cast<float>(engMouseY())));

	Vector target_position = Vector::lerp(player_position, mouse_position, 0.3f);

	position = Vector::lerp(position, target_position, CAMERA_SPEED * engDeltaTime());
}

Vector Camera::worldToScreen(Vector vec) {
	return vec - position;
}

Vector Camera::screenToWorld(Vector vec) {
	return vec + position;
}
