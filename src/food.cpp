#include "FOOD.H"

	
void Food::Spawn()
{
	position.x = GetRandomValue(0, 800 / cellSize - 1);
	position.y = GetRandomValue(0, 600 / cellSize - 1);
}

void Food::Draw()
{
	DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
}

Vector2 Food::GetPosition()
{
	return position;
}
