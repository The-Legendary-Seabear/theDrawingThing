#pragma once
#pragma once
#include "game.h"

class Food {
private:
    Vector2 position;
public:
    int cellSize = 20;
    void Spawn();
    void Draw();
    Vector2 GetPosition();
};
