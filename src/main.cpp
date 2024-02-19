#include "Engine/TinyEngine.h"

void update_input(float& x, float& y, float& speed);

int main()
{
	engInit("Tiny Engine", 800, 600);

	engSetDrawColor(COLOR_DARK_GRAY);
	engClearScreen();

	float x = 0.f;
	float y = 0.f;

	float speed = 100.0f;

	update_input(x, y, speed);
}

void update_input(float& x, float& y, float& speed) {
	while (engBeginFrame()) {
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		engSetDrawColor(COLOR_SALMON);
		engFillRect(x, y, 32, 32);

		engDrawTextF(10, 10, "Speed: %f", speed);
		if (engKeyDown(Key::W)) {
			y -= speed * engDeltaTime();
		}
		if (engKeyDown(Key::S)) {
			y += speed * engDeltaTime();
		}
		if (engKeyDown(Key::A)) {
			x -= speed * engDeltaTime();
		}
		if (engKeyDown(Key::D)) {
			x += speed * engDeltaTime();
		}

		if (engKeyPressed(Key::E)) {
			speed += 50.f;
		}
		if (engKeyPressed(Key::Q)) {
			speed -= 50.f;
		}
	}
}