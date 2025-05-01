#include "GAME.H"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	InitWindow(screen_Width, screen_Height, "Snake");
	SetTargetFPS(10);
	food.Spawn();
}

void Game::run()
{
	while (isRunning && !WindowShouldClose()) {
		update();
		BeginDrawing();
		render();
		EndDrawing();
	}
	shutDown();
}

void Game::render()
{
	ClearBackground(DARKGREEN);
	snake.draw();
	food.Draw();
}

void Game::update()
{
	snake.update();

	if (snake.checkCollision()) {
		isRunning = false;
	}

	if (snake.getHeadPosition().x == food.GetPosition().x && snake.getHeadPosition().y == food.GetPosition().y) {
		snake.grow();
		food.Spawn();
	}

	if (IsKeyPressed(KEY_UP)) snake.setDirection({ 0, -1 });
	if (IsKeyPressed(KEY_DOWN)) snake.setDirection({ 0, 1 });
	if (IsKeyPressed(KEY_LEFT)) snake.setDirection({ -1, 0 });
	if (IsKeyPressed(KEY_RIGHT)) snake.setDirection({ 1, 0 });
}

void Game::shutDown()
{
	CloseWindow();
}
