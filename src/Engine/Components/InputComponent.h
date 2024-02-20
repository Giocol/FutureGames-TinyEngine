#pragma once
class InputComponent
{
public:
	InputComponent(float playerX, float playerY, float playerSpeed);
	~InputComponent() {};

	void inputTick();
private:
	float playerX;
	float playerY;
	float playerSpeed;
};

