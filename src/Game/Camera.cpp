#include "Camera.h"

void Camera::update() {
	position = game->get_player()->position;
}

Vector Camera::worldToScreen(Vector vec) {
	return vec - position;
}

Vector Camera::screenToWorld(Vector vec) {
	return vec + position;
}
