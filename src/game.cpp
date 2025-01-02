#include "game.h"

Game::Game() {
    this->ballManager = BallManager();

    this->init();
}

Game::Game(UpgradeManager *upgradeManager) {
    this->upgradeManager = upgradeManager;
    this->ballManager = BallManager(upgradeManager);

    this->init();
}

Game Game::init() {
    this->blockManager.init();
    this->ballManager.init();

    return *this;
}

void Game::update() {
    this->ballManager.update(this->blockManager.block);
    increasePoints(this->blockManager.update());

    // If there are no more blocks, reset the state
    if (this->blockManager.blocksEmpty()) {
        resetState();
    }
}

void Game::resetState() {
    this->ballManager.init();
    this->blockManager.init();
    this->upgradeManager->resetState();
}

void Game::draw(int xOffset, int yOffset) {
    this->blockManager.draw();
    this->ballManager.draw();

    DrawRectangleLines(GAME_X_OFFSET-1, GAME_Y_OFFSET-1, GAME_WIDTH + 1, GAME_HEIGHT + 1, NEON_GREEN);
}

void Game::increasePoints(int score) {
    this->upgradeManager->breakPoints += score;
}
