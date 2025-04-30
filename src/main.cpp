/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "editor.h"
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "raymath.h"
#include <vector>


int main ()
{

	const int screen_width = 1280;
	const int screen_height = 800;
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screen_width, screen_height, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	Texture baubau = LoadTexture("bau.png");
	
	//This is stuff we did in class on 4/28
	Editor editor;
	while (!WindowShouldClose()) {

		editor.update();
		
		BeginDrawing();
		ClearBackground(BLACK);
		//DrawTexture(wabbit, 400, 200, WHITE);
		editor.draw();
		EndDrawing();
	}

	// game loop
	//while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	//{
		// drawing
		//BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		//ClearBackground(BLACK);

		// draw some text using the default font
		//DrawText("Hello Raylib", 200,200,20,RED);

		//float rate = 3.0f;
		//float amplitude = 10.0f;

		// draw our texture to the screen
		//for (int i = 0; i < screen_width; i++) {
			//the i++ affects how close apart each image is, if it is i++ they are really close together and if it is i+=100 is is really far apart
			//This moves the picture in a tangent line, making it look like the picture is raining down from the screen and out of view.
			//The 100 at the end affects the mid point of the tangent line and how long each picture stays there
			//the .0050f changes the pictures size
			//int y = screen_height / 2 + (tanf(GetTime() + i / 0.0050f) * 100);
			//float scale = 0.1f + (sinf(GetTime() + rate) + (i / 50.0f) * amplitude);
		//DrawTexture(baubau, i, y, WHITE);
			//Vector2 v;
			//v.x = i;
			//v.y = y;
			//DrawTextureEx(baubau, v, 0, 0.1f, GREEN);
			//DrawTextureEx(baubau, (Vector2){i,y}, 0, scale, WHITE);

			//DrawCircleV((Vector2) { i, y }, scale, GREEN;

		//}
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		//EndDrawing();
	//}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);
	//UnloadTexture(baubau);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
