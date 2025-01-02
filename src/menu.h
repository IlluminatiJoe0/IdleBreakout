#pragma once

#include "raylib.h"
#include "game.h"
#include "constants.h"

class Menu {
public:
    Menu();
    Menu(int x, int y, int width, int height, int xOffset, int yOffset, Game* game);

    void draw();
    void update();

private:
    int x;
    int y;
    int width;
    int height;
    int xOffset;
    int yOffset;

    Game* game;
};