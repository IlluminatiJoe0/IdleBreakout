#pragma once

#include "raylib.h"
#include "game.h"
#include "constants.h"
#include "upgradeManager.h"
#include "menuBreakUpgradeCells.h"

class Menu {
public:
    Menu();
    Menu(int x, int y, int width, int height, int xOffset, int yOffset, UpgradeManager* upgradeManager);
    
    MenuBreakUpgradeCells menuBreakUpgradeCells;

    void draw();
    void update();

private:
    int x;
    int y;
    int width;
    int height;
    int xOffset;
    int yOffset;

    UpgradeManager* upgradeManager;
};