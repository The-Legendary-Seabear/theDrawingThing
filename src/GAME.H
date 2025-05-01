#pragma once
#include "raylib.h"
#include "snake.h"
#include "food.h"

class Game {
private:
	bool isRunning = true;
		const int screen_Width = 800;
		const int screen_Height = 600;
		
		Snake* snake = new Snake;
		Snake testSnake;
		Food* food = new Food;
public:
		const int cell_Size = 20;

	Game();
	~Game();

	void init();
	void run();
	void render();
	void update();
	void shutDown();


	
};