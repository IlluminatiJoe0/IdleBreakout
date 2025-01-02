#include "raylib.h"
#include "game.h"
#include "constants.h"

#include "resource_dir.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Idle Breakout");
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);

	Game game;
	game.init();
	
	while (!WindowShouldClose())
	{
		game.update();

		BeginDrawing();
		ClearBackground(MODERN_BLACK);

		game.draw(GAME_X_OFFSET, GAME_Y_OFFSET);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
