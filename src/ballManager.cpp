#include "ballManager.h"

BallManager::BallManager() {
    this->ballCount = 10;
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
    this->balls.clear();
    for (int i = 0; i < this->ballCount; i++) {
        spawnBall();
    }
}

void BallManager::spawnBall() {
    this->balls.push_back(new Ball(GAME_CENTER_X + GAME_X_OFFSET, BALL_SPAWN_Y - GAME_Y_OFFSET));
}

void BallManager::destroyBall(Ball *ball) {
    this->balls.erase(remove(this->balls.begin(), this->balls.end(), ball), this->balls.end());
}

// Bonus methods

void BallManager::increaseBallCountByFlatAmount(int amount) {
    this->bonusBallCount += amount;
}

void BallManager::increaseBallCountByMultiplier(float multiplier) {
    this->bonusBallCountMultiplier *= multiplier;
}

void BallManager::increaseSpeedByFlatAmount(float amount) {
    this->speedBonus += amount;
}

void BallManager::increaseSpeedByMultiplier(float multiplier) {
    this->speedMultiplier *= multiplier;
}

void BallManager::increaseLifetimeByFlatAmount(float amount) {
    this->lifetimeBonus += amount;
}

void BallManager::increaseLifetimeByMultiplier(float multiplier) {
    this->lifetimeMultiplier *= multiplier;
}

void BallManager::decreaseSpawnTimerByFlatAmount(float amount) {
    this->spawnTimerBonus -= amount;
}

void BallManager::decreaseSpawnTimerByMultiplier(float multiplier) {
    this->spawnTimerMultiplier *= multiplier;
}

//