#pragma once

#include "raylib.h"
#include "manager/soundManager.h"
#include "util/constants.h"
#include <iostream>

class Block {
public:
    Block();
    Block(int x, int y);
    Rectangle bounds;

    bool isDestroyed = false;
    bool isCollected = false;

    void draw();
    void hit();

    bool checkIsDestroyed();

private:
    int x;
    int y;
    int health;
    
};