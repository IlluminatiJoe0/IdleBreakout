#pragma once

#include "upgradeManager.h"
#include "raylib.h"
#include "constants.h"
#include <vector>

class MenuBreakUpgradeCells {
public:
    MenuBreakUpgradeCells();
    MenuBreakUpgradeCells(UpgradeManager *upgradeManager, int x, int y, int width, int height);

    void draw();
    void update();
    void checkCellClicked();

private:
    UpgradeManager* upgradeManager;

    void init();

    int x, y, width, height, xOffset, yOffset;

    // vector of upgrade cells TODO:
};