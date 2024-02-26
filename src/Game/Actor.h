#pragma once
#include "Math/Vector.h"
#include "Engine/TinyEngine.h"

class Actor {
public:
	Actor(Vector position, Vector size, Color color)
		: position(position), size(size), color(color) { }

	virtual void update() {}
	virtual void render();

	Vector position;
	Vector size = Vector(32);
	Color color = COLOR_WHITE;
};

