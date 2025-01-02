#include "game.h"

Game::Game() {
    this->ballManager = BallManager();
    this->score = 0;

    this->init();
}

Game Game::init() {
    this->blockManager.init();
    this->ballManager.init();

    this->score = 0;

    return *this;
}

void Game::update() {
    this->ballManager.update(this->blockManager.block);
    increasePoints(this->blockManager.update());
}

void Game::draw(int xOffset, int yOffset) {
    this->blockManager.draw();
    this->ballManager.draw();

    DrawRectangleLines(GAME_X_OFFSET-1, GAME_Y_OFFSET-1, GAME_WIDTH + 1, GAME_HEIGHT + 1, NEON_GREEN);
}

void Game::increasePoints(int score) {
    this->score += score;
}
