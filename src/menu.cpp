#include "menu.h"
#include <iostream>

Menu::Menu() {
    this->height = 0;
    this->width = 0;
    this->x = 0;
    this->y = 0;
    this->xOffset = 0;
    this->yOffset = 0;
}

Menu::Menu(int x, int y, int width, int height, int xOffset, int yOffset, Game* game) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xOffset = 0;
    this->yOffset = 0;
    this->game = game;
}

void Menu::draw() {
    DrawRectangleLines(this->x, this->y, this->width, this->height, NEON_GREEN);

    std::string buffer = "Score: " + this->game->score.str;
    int width = MeasureText(buffer.c_str(), 6);
    DrawText(buffer.c_str(), this->x + this->width / 2 - width / 2, this->y + this->height / 2, 6, NEON_GREEN);

}

void Menu::update() {

}
