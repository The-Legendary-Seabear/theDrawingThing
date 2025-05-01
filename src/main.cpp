#include "game.h"
#include "food.h"
#include "snake.h"
#include "raymath.h"
#include "raylib.h"
#include "../build/build_files/GAME.H"

int main() {
	Game game;
	game.init();
	game.run();
}