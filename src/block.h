#pragma once

#include "raylib.h"

class Block {
public:
    Block();
    Block(int x, int y);
    Rectangle bounds;

    bool isDestroyed = false;

    void draw();
    void hit();

private:
    int x;
    int y;
    int health;
    
};