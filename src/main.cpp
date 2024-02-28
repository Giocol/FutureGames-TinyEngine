#include "Engine/TinyEngine.h"
#include "Game/Game.h"
#include "Config.h"

int main()
{
	engInit("Tiny Engine", Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);

	engSetDrawColor(COLOR_DARK_GRAY);
	engClearScreen();

	game = new Game();

	game->initGame();

	game->gameLoop();

	delete game;
}