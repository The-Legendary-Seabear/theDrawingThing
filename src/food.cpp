#include "food.h"


	
Food::Food() {

}

Food::~Food()
{
}

void Food::spawn()
{
	position.x = GetRandomValue(0, 800 / cellSize - 1);
	position.y = GetRandomValue(0, 600 / cellSize - 1);
}

void Food::draw()
{
	DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
}

Vector2 Food::getPosition()
{
	return position;
}
