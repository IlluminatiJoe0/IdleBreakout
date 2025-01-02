#include "blockManager.h"

BlockManager::BlockManager() {

}

void BlockManager::initBlocks() {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            block[i][j] = Block(j, i);
        }
    }
}

void BlockManager::draw() {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            block[i][j].draw();
        }
    }
}

void BlockManager::init() {
    this->initBlocks();
}

int BlockManager::update() {
    int count = 0;

    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            if (block[i][j].checkIsDestroyed()) {
                count++;
            }
        }
    }

    return count;
}

bool BlockManager::blocksEmpty() {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            if (!block[i][j].isDestroyed) {
                return false;
            }
        }
    }
    return true;
}
