#pragma once

#include "block.h"
#include "util/constants.h"

class BlockManager {
public: 
    BlockManager();
    Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X];

    void initBlocks();
    void draw();
    void init();

    int update();

    bool blocksEmpty();

private:
    

};