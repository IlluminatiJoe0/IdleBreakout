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

    int ballCount;
    float speed;
    float lifetime;
    float spawnTimer;

private:
    vector<Ball*> balls;
};