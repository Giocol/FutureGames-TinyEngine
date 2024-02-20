#include "InputComponent.h"
#include "../TinyEngine.h"

InputComponent::InputComponent(float playerX, float playerY, float playerSpeed) {
	this->playerX = playerX;
	this->playerY = playerY;
	this->playerSpeed = playerSpeed;
}

void InputComponent::inputTick() {
	engSetDrawColor(COLOR_DARK_GRAY);
	engClearScreen();

	engSetDrawColor(COLOR_SALMON);
	engFillRect(playerX, playerY, 32, 32);

	engDrawTextF(10, 10, "Speed: %f", playerSpeed);
	if (engKeyDown(Key::W)) {
		playerY -= playerSpeed * engDeltaTime();
	}
	if (engKeyDown(Key::S)) {
		playerY += playerSpeed * engDeltaTime();
	}
	if (engKeyDown(Key::A)) {
		playerX -= playerSpeed * engDeltaTime();
	}
	if (engKeyDown(Key::D)) {
		playerX += playerSpeed * engDeltaTime();
	}

	if (engKeyPressed(Key::E)) {
		playerSpeed += 50.f;
	}
	if (engKeyPressed(Key::Q)) {
		playerSpeed -= 50.f;
	}
}
