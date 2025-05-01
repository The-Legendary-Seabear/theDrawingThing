#include "GAME.H"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	InitWindow(screen_Width, screen_Height, "Snake");
	SetTargetFPS(5);
	food->spawn();
}

void Game::run()
{
	while (isRunning && !WindowShouldClose()) {
		update();
		BeginDrawing();
		render();
		EndDrawing();
		std::cout << isRunning << std::endl;
	}
	shutDown();
}

void Game::render()
{
	ClearBackground(DARKGREEN);
	snake->draw();
	food->draw();
}

void Game::update()
{
	Vector2 foodPos = food->getPosition();
	snake->update(foodPos);

	if (snake->checkCollision()) {
		isRunning = false;
	}

	if (snake->getHeadPosition().x == food->getPosition().x && snake->getHeadPosition().y == food->getPosition().y) {
		snake->grow();
		food->spawn();
	}

	if (IsKeyPressed(KEY_UP)) snake->setDirection({ 0, -1 });
	if (IsKeyPressed(KEY_DOWN)) snake->setDirection({ 0, 1 });
	if (IsKeyPressed(KEY_LEFT)) snake->setDirection({ -1, 0 });
	if (IsKeyPressed(KEY_RIGHT)) snake->setDirection({ 1, 0 });
}

void Game::shutDown()
{
	CloseWindow();
}
