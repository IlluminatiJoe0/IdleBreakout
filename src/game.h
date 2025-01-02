#pragma once

#include "block.h"
#include "util/constants.h"
#include "manager/ballManager.h"
#include "util/bigint.h"
#include "manager/blockManager.h"
#include "manager/upgradeManager.h"

class Game {
public:
    Game();
    Game(UpgradeManager* upgradeManager);
    Game init();
    
    void update();
    void resetState();
    void draw(int xOffset, int yOffset);
    void increasePoints(int score);

private:
    BallManager ballManager;
    BlockManager blockManager;
    UpgradeManager* upgradeManager;
    
};