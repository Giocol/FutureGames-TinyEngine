#pragma once
#include "Math/Vector.h"
#include "Engine/TinyEngine.h"

enum class CollisionChannel {
	Player,
	Enemy,
	Bullet,
	Pickup,
	None
};

class Actor {
public:
	Actor(Vector position, Vector size, Color color)
		: position(position), size(size), color(color) { }
	virtual ~Actor() {};

	virtual void update() {}
	virtual void render();

	void destroy() { isDestroyed = true; }
	bool getIsDestroyed() { return isDestroyed; }

	virtual void hit(int) { destroy(); }

	Vector position;
	Vector size = Vector(32);
	Color color = COLOR_WHITE;

	CollisionChannel collisionChannel = CollisionChannel::None;

private:
	bool isDestroyed = false;
};

