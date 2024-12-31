#pragma once

#include "raylib.h"
#include "constants.h"
#include "block.h"

class Ball {
public:
    Ball();
    Ball(int x, int y);
    void draw();
    void update(float speed, Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]);

private:
    int x;
    int y;
    int radius;
    Vector2 velocity;

    void move(float speed);
    void checkCollision(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X], float speed);
};