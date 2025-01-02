#include "ballManager.h"

BallManager::BallManager() {
    this->ballCount = 1;
    this->speed = 3.0f;
    this->lifetime = 10.0f;
    this->spawnTimer = 15.0f;
}

BallManager::BallManager(UpgradeManager *upgradeManager) {
    this->ballCount = 1;
    this->speed = 3.0f;
    this->lifetime = 10.0f;
    this->spawnTimer = 15.0f;
    this->upgradeManager = upgradeManager;
}

void BallManager::update(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]) {
    for (Ball* ball : this->balls) {
        ball->update(this->speed, block);
    }
}

void BallManager::draw() {
    for (Ball* ball : this->balls) {
        ball->draw();
    }
}

void BallManager::init() {
    this->balls.clear();
    for (int i = 0; i < this->ballCount; i++) {
        spawnBall();
    }
}

void BallManager::spawnBall() {
    this->balls.push_back(new Ball(GAME_CENTER_X + GAME_X_OFFSET, BALL_SPAWN_Y - GAME_Y_OFFSET, this->upgradeManager));
}

void BallManager::destroyBall(Ball *ball) {
    this->balls.erase(remove(this->balls.begin(), this->balls.end(), ball), this->balls.end());
}