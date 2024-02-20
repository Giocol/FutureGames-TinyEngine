#pragma once
class InputComponent
{
public:
	InputComponent(float playerX, float playerY, float playerSpeed);
	~InputComponent() {};

	void input_tick();
private:
	float playerX;
	float playerY;
	float playerSpeed;
};

