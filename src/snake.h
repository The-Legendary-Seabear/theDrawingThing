#pragma once
#pragma once
#include "game.h"
#include <deque>

class Snake {
private:
	std::deque<Vector2> body;
	Vector2 direction;

	
public:
    Snake();

    void update();
    void draw();
    void grow();
    bool checkCollision();
    void setDirection(Vector2 newDir);
    Vector2 getHeadPosition();
};
