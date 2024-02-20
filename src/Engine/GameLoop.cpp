#include "GameLoop.h"

InputComponent* inputComponent = nullptr; // this sucks

void initGame() {
	inputComponent = new InputComponent(0.f, 0.f, 100.f);
}

void gameLoop() {

	while (engBeginFrame()) {
		inputComponent->input_tick();
	}
}