#pragma once
#include "raylib.h"

class Food {
private:
    Vector2 position;
public:
    Food();
    ~Food();
    int cellSize = 20;
    void spawn();
    void draw();
    Vector2 getPosition();
};
