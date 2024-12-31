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

void Game::draw() {
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            block[i][j].draw();
        }
    }

    this->ballManager.draw();
}
