#include "menu.h"

Menu::Menu() {
    this->height = 0;
    this->width = 0;
    this->x = 0;
    this->y = 0;
    this->xOffset = 0;
    this->yOffset = 0;
}

Menu::Menu(int x, int y, int width, int height, int xOffset, int yOffset, UpgradeManager* upgradeManager) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xOffset = xOffset;
    this->yOffset = yOffset;
    this->upgradeManager = upgradeManager;
    this->menuBreakUpgradeCells = MenuBreakUpgradeCells(upgradeManager, x + xOffset, y + yOffset * 5, width - xOffset*2, height - yOffset*6);
}

void Menu::draw() {
    DrawRectangleLines(this->x, this->y, this->width, this->height, NEON_GREEN);

    // Draw Break Points value
    std::string buffer = this->upgradeManager->breakPoints.str;
    int width = MeasureText(buffer.c_str(), 24);
    DrawText(buffer.c_str(), this->x + this->width / 2 - width / 2, this->y + this->yOffset * 2, 24, NEON_GREEN);

    // Draw Score text
    std::string scoreText = "Break Points";
    int scWidth = MeasureText(scoreText.c_str(), 20);
    DrawText(scoreText.c_str(), this->x + this->width / 2 - scWidth / 2, this->y + this->yOffset, 20, NEON_GREEN);

    // FPS
    char fps[8];
    sprintf(fps, "%d", GetFPS());
    DrawText(fps, 0, 0, 10, NEON_GREEN);

    this->menuBreakUpgradeCells.draw();
}

void Menu::update() {
    this->menuBreakUpgradeCells.update();
}
