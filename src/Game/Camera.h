#pragma once
#include "Math/Vector.h"

class Camera {
public:
	void update();
	Vector worldToScreen(Vector vec);
	Vector screenToWorld(Vector vec);
private:
	Vector position;
	static constexpr float CAMERA_SPEED = 8.5f;
};

