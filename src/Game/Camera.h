#pragma once

#include <Math/Vector.h>

class Player;

class Camera{
public:
	Camera(Player* player) : player(player) { };
	~Camera() = default;
	void update();

	static constexpr float CAMERA_SPEED = 8.5f;

	Vector worldToScreen(Vector vec);
	Vector screenToWorld(Vector vec);

	Vector position;
	Player* player;
};

