#include "Actor.h"
#include "Game.h"

void Actor::render() {
	Vector drawPosition = position - size * .5f;
	drawPosition = game->get_camera().worldToScreen(drawPosition);

	engSetDrawColor(color);
	engFillRect(
		(int) drawPosition.x,
		(int) drawPosition.y,
		(int) size.x,
		(int) size.y
	);
}
