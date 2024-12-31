#pragma once

#include "block.h"
#include "constants.h"
#include "ballManager.h"

using namespace std;

class Game {
public:
    Game();
    Game init();
    
    void initBlocks();
    void update();
    void draw();

private:
    Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X];
    BallManager ballManager;
    
};