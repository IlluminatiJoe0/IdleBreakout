#pragma once

#include "block.h"
#include "constants.h"
#include "ballManager.h"
#include "bigint.h"
#include "blockManager.h"
#include "upgradeManager.h"

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