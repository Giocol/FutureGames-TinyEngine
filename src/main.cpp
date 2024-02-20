#include "Engine/TinyEngine.h"
#include "Engine/GameLoop.h"

int main()
{
	engInit("Tiny Engine", 800, 600);

	engSetDrawColor(COLOR_DARK_GRAY);
	engClearScreen();

	initGame();

	gameLoop();

}