#pragma once
#include "Actor.h"
#include "Game.h"

class Camera : public Actor {
public:
	void update();
	Vector worldToScreen(Vector vec);
	Vector screenToWorld(Vector vec);
};

