#pragma once

#include "block.h"
#include "constants.h"
#include "ballManager.h"
#include "bigint.h"
#include "blockManager.h"

class Game {
public:
    Game();
    Game init();

    bigint score;
    
    void update();
    void draw(int xOffset, int yOffset);
    void increasePoints(int score);

private:
    BallManager ballManager;
    BlockManager blockManager;
    
};