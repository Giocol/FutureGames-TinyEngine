#include "Game.h"

Game game;

void Game::initGame() {
	actors[0] = new Player(Vector(100.f, 100.f));
	player = actors[0];

	actors[1] = new Enemy(Vector(600.f, 250.f));
	actors[2] = new Enemy(Vector(300.f, 250.f));

}

void Game::gameLoop() {
	while (engBeginFrame()) {
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		if (engKeyPressed(Key::Escape))
		{
			return;
		}

		update();
		render();
	}
}

void Game::update() {
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->update();
		}
	}
}

void Game::render() {
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->render();
		}
	}
}
