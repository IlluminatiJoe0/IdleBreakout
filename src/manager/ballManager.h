#pragma once

#include "ball.h"
#include "util/constants.h"
#include <vector>
#include <algorithm>
#include "upgradeManager.h"

using namespace std;

class BallManager {
public:
    BallManager();
    BallManager(UpgradeManager* upgradeManager);
    void update(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]);
    void draw();
    void init();
    void spawnBall();
    void destroyBall(Ball* ball);
    void despawnBall();

private:
    vector<Ball*> balls;

    UpgradeManager* upgradeManager;

    int ballCount;
    float speed;
    float lifetime;
    float spawnTimer;

};