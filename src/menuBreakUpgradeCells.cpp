#include "menuBreakUpgradeCells.h"

MenuBreakUpgradeCells::MenuBreakUpgradeCells() {}

MenuBreakUpgradeCells::MenuBreakUpgradeCells(UpgradeManager *upgradeManager, int x, int y, int width, int height) {
    this->upgradeManager = upgradeManager;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xOffset = UPGRADE_MENU_X_OFFSET;
    this->yOffset = UPGRADE_MENU_Y_OFFSET;

    this->init();
}

void MenuBreakUpgradeCells::draw() {
    DrawRectangleLines(this->x, this->y, this->width, this->height, NEON_GREEN);

    // Draw the cells
}

void MenuBreakUpgradeCells::update() {
    checkCellClicked();
}

void MenuBreakUpgradeCells::checkCellClicked() {

}

void MenuBreakUpgradeCells::init() {

}
