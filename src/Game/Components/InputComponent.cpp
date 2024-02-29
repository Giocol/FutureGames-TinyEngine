#include "InputComponent.h"

void input_tick(Vector& position, float& speed) {
	Vector input;

	if (engKeyDown(Key::W))
		input.y -= 1.f;
	if (engKeyDown(Key::S))
		input.y += 1.f;
	if (engKeyDown(Key::D))
		input.x += 1.f;
	if (engKeyDown(Key::A))
		input.x -= 1.f;

	input.normalize();
	position += input * speed * engDeltaTime();
	//position = position + input * speed * engDeltaTime();

	if (engKeyPressed(Key::E))
		speed += 50.f;
	if (engKeyPressed(Key::Q))
		speed -= 50.f;
	
	if (engMouseButtonPressed(Mouse_Button::Left)) {
		//spawn bullet
		Vector mousePosition = Vector(static_cast<float>(engMouseX()), static_cast<float>(engMouseY()));
		mousePosition = game->get_camera().screenToWorld(mousePosition);

		Vector bulletDirection = mousePosition - position;
		bulletDirection.normalize();
		game->spawn_actor(new Bullet(position, bulletDirection));
	}
}
