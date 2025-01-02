#pragma once

#include "block.h"
#include "constants.h"
#include "ballManager.h"
#include "bigint.h"

class Game {
public:
    Game();
    Game init();

    bigint score;
    
    void initBlocks();
    void update();
    void draw(int xOffset, int yOffset);
    void increasePoints();

private:
    Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X];
    BallManager ballManager;
    
};