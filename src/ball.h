#pragma once

#include "raylib.h"
#include "util/constants.h"
#include "block.h"
#include "manager/upgradeManager.h"
#include "raymath.h"
#include "util/randomizer.h"
#include <algorithm>
#include <iostream>

class Ball {
public:
    Ball();
    Ball(int x, int y, UpgradeManager* upgradeManager);
    void draw();
    void drawArc(float progress);
    void update(float speed, Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]);

private:
    float x;
    float y;
    int radius;
    float angle;

    UpgradeManager* upgradeManager;

    void move(float speed);
    void reverseHorizontalDirection();
    void reverseVerticalDirection();
    void ensureNonZeroDirection();
    void checkCollision(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X], float speed);
};