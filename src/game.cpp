#include "game.h"

Game::Game() {
}

Game Game::init() {
    initBlocks();
    this->ballManager.init();

    return Game();
}

void Game::initBlocks() {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            block[i][j] = Block(j, i);
        }
    }
}

void Game::update() {
    this->ballManager.update(this->block);
}

void Game::draw(int xOffset, int yOffset) {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            block[i][j].draw();
        }
    }

    this->ballManager.draw();

    DrawRectangleLines(GAME_X_OFFSET-1, GAME_Y_OFFSET-1, GAME_WIDTH + 1, GAME_HEIGHT + 1, NEON_GREEN);
}
