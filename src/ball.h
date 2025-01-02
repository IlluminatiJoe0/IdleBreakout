#pragma once

#include "raylib.h"
#include "constants.h"
#include "block.h"
#include "upgradeManager.h"

class Ball {
public:
    Ball();
    Ball(int x, int y, UpgradeManager* upgradeManager);
    void draw();
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