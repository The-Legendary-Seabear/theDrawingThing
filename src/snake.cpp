#include "SNAKE.H"

Snake::Snake()
{
	body.push_back({ 10, 10 });
	direction = { 1, 0 };

}

void Snake::update()
{
	Vector2 newHead = body.front();
	newHead.x += direction.x;
	newHead.y += direction.y;
	body.push_front(newHead);
	body.pop_back();
}

void Snake::draw()
{
	int cellSize = 20;
	for (auto& segment : body) {
		DrawRectangle(segment.x * cellSize, segment.y * cellSize, cellSize, cellSize, GREEN);
	}
}

void Snake::grow()
{
	//The way i think this works is that on the cell that we eat the apple the game doesn't get updated right away, so when the game updates and the snake goes forward one cell
	//The game updates with the head in the new cell and we push back the body to create the new length after eating the apple.
	Vector2 tail = body.back();
	body.push_back(tail);
	
}

bool Snake::checkCollision()
{
	Vector2 head = body.front();

	//The way this works is to see if the head of the snake exceeds the border limit by making the snake stay between a width of 0 - 800 and a height of 0 - 600

	if (head.x <= 0 || head.x >= 800 / cellSize || head.y <= 0 || head.y >= 600 / cellSize) {
		return true;
	}

	
	for (int snakeSegment = 1; snakeSegment < body.size(); snakeSegment++) {
		if (body[snakeSegment].x == head.x || body[snakeSegment].y == head.y) {
			return true;
		}
	}

	return false;
}

void Snake::setDirection(Vector2 newDir)
{
	//This checks to see if the user trys to go back, since we don't want them to try to go back and accidentally kill themselves, it just invalidates their attempt.
	if (body.size() > 1 && (newDir.x == -direction.x || newDir.y == -direction.y)) {
		return;
	}
	else {
	direction = newDir;
	return;
	}
}

Vector2 Snake::getHeadPosition()
{
	return body.front();
}
