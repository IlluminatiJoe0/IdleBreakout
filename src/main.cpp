#include "raylib.h"
#include "game.h"
#include "constants.h"

#include "resource_dir.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(1280, 800, "Idle Breakout");
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);

	Game game;
	game.init();
	
	while (!WindowShouldClose())
	{
		game.update();

		BeginDrawing();
		ClearBackground(MODERN_BLACK);

		game.draw();
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
