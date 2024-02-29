#pragma once
#include "Math/Vector.h"

class Camera {
public:
	void update();
	Vector worldToScreen(Vector vec);
	Vector screenToWorld(Vector vec);
private:
	Vector position;
};

