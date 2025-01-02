#pragma once

#include "ball.h"
#include "constants.h"
#include <vector>
#include <algorithm>

using namespace std;

class BallManager {
public:
    BallManager();
    void update(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]);
    void draw();
    void init();
    void spawnBall();
    void destroyBall(Ball* ball);

    void increaseBallCountByFlatAmount(int amount);
    void increaseBallCountByMultiplier(float multiplier);
    void increaseSpeedByFlatAmount(float amount);
    void increaseSpeedByMultiplier(float multiplier);
    void increaseLifetimeByFlatAmount(float amount);
    void increaseLifetimeByMultiplier(float multiplier);
    void decreaseSpawnTimerByFlatAmount(float amount);
    void decreaseSpawnTimerByMultiplier(float multiplier);

private:
    vector<Ball*> balls;

    int ballCount;
    float speed;
    float lifetime;
    float spawnTimer;

    int bonusBallCount = 0;
    float bonusBallCountMultiplier = 1.0f;
    float speedMultiplier = 1.0f;
    float speedBonus = 0.0f;
    float lifetimeMultiplier = 1.0f;
    float lifetimeBonus = 0.0f;
    float spawnTimerMultiplier = 1.0f;
    float spawnTimerBonus = 0.0f;
};