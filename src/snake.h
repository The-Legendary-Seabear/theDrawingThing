#pragma once
#include "raylib.h"
#include <deque>

class Snake {
private:
	std::deque<Vector2> body;
	Vector2 direction;
    const int cellSize = 20;
    bool shouldGrow = false;
    
	
public:
    Snake();
    ~Snake();

    void update(Vector2 foodPosition);
    void draw();
    void grow();
    bool checkCollision();
    void setDirection(Vector2 newDir);
    Vector2 getHeadPosition();
};
