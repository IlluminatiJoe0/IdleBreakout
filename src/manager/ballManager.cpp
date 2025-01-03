#include "ballManager.h"

float sTimer = 0.0f;
float dsTimer = 0.0f;

BallManager::BallManager() {
    this->ballCount = 0;
    this->speed = 0.0f;
    this->lifetime = 0.0f;
    this->spawnTimer = 0.0f;
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

    if (this->balls.size() > 0) {
        dsTimer += GetFrameTime();

        if (dsTimer > this->lifetime) {
            despawnBall();
            dsTimer = 0.0f;
        }
    }

    if (sTimer <= this->spawnTimer) {
        sTimer += GetFrameTime();
    }

    if (this->balls.size() < this->ballCount) {
        if (sTimer > this->spawnTimer) {
            spawnBall();
            sTimer = 0.0f;
        }
    }
}

void BallManager::draw() {
    for (Ball* ball : this->balls) {
        if (ball == this->balls.back()){
            ball->drawArc(dsTimer / this->lifetime);
        } else {
            ball->draw();  
        }    
    }

    DrawRectangle(GAME_X_OFFSET, 5, 0 + GAME_WIDTH * (sTimer / this->spawnTimer), 10, DULL_GREEN);
}

void BallManager::init() {
    this->balls.clear();
    for (int i = 0; i < this->ballCount; i++) {
        spawnBall();
    }
}

void BallManager::spawnBall() {
    if (this->balls.size() >= this->ballCount) {return;}
    
    this->balls.push_back(new Ball(GAME_CENTER_X + GAME_X_OFFSET, BALL_SPAWN_Y - GAME_Y_OFFSET, this->upgradeManager));
}

void BallManager::destroyBall(Ball *ball) {
    this->balls.erase(remove(this->balls.begin(), this->balls.end(), ball), this->balls.end());
}

void BallManager::despawnBall() {
    if (this->balls.size() <= 0) {return;}

    this->balls.pop_back();
}