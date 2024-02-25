#include "Actor.h"

void Actor::render() {
	engSetDrawColor(color);
	engFillRect(
		(int)(position.x - size.x / 2),
		(int)(position.y - size.y / 2),
		(int)size.x,
		(int)size.y
	);
}
