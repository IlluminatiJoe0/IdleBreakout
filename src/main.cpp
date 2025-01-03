#include "raylib.h"
#include "game.h"
#include "util/constants.h"
#include "menu/menu.h"
#include "manager/soundManager.h"
#include "manager/upgradeManager.h"

#include "resource_dir.h"

using namespace std;

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Idle Breakout");
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);
	InitAudioDevice();

	SoundManager::GetInstance().LoadSounds();

	UpgradeManager upgradeManager;
	Game game = Game(&upgradeManager);
	Menu menu = Menu(GAME_X_OFFSET * 2 + GAME_WIDTH, GAME_Y_OFFSET, WINDOW_WIDTH - GAME_WIDTH - GAME_X_OFFSET * 3, GAME_HEIGHT, GAME_X_OFFSET, GAME_Y_OFFSET, &upgradeManager);
	
	while (!WindowShouldClose())
	{
		game.update();
		menu.update();

		BeginDrawing();
		ClearBackground(MODERN_BLACK);

		game.draw(GAME_X_OFFSET, GAME_Y_OFFSET);
		menu.draw();
		
		EndDrawing();
	}

	SoundManager::GetInstance().UnloadSounds();
	CloseAudioDevice();

	CloseWindow();
	return 0;
}
