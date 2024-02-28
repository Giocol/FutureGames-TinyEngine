#include "Engine/TinyEngine.h"
#include "Game/Game.h"

int main()
{
	engInit("Tiny Engine", 800, 600);

	engSetDrawColor(COLOR_DARK_GRAY);
	engClearScreen();

	game = new Game();

	game->initGame();

	game->gameLoop();

	delete game;
}