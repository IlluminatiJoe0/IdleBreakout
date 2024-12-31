#include "ballManager.h"

BallManager::BallManager() {
    this->ballCount = 1;
    this->speed = 3.0f;
    this->lifetime = 10.0f;
    this->spawnTimer = 15.0f;
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
    for (int i = 0; i < this->ballCount; i++) {
        spawnBall();
    }
}

void BallManager::spawnBall() {
    this->balls.push_back(new Ball(WINDOW_CENTER_X, BALL_SPAWN_Y));
}

void BallManager::destroyBall(Ball *ball) {
    this->balls.erase(remove(this->balls.begin(), this->balls.end(), ball), this->balls.end());
}
