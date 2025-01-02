#pragma once

#include <string>
#include "util/upgradeType.h"
#include "util/bigint.h"

class UpgradeManager {
public:
    bigint breakPoints = 0;

    void resetState() {
        // Only reset the upgrades that are reset when the board is cleared
        
    }

    void ApplyUpgrade(UpgradeType upgradeName, float amount) {
        if (upgradeName == UpgradeType::BALL_SPEED_ADD) { speedBonus += amount; }
        else if (upgradeName == UpgradeType::BALL_SPEED_MULT) { speedMultiplier *= amount; }
        else if (upgradeName == UpgradeType::BALL_LIFETIME_ADD) { lifetimeBonus += amount; }
        else if (upgradeName == UpgradeType::BALL_LIFETIME_MULT) { lifetimeMultiplier *= amount; }
        else if (upgradeName == UpgradeType::BALL_SPAWNTIME_ADD) { spawnTimerBonus -= amount; }
        else if (upgradeName == UpgradeType::BALL_SPAWNTIME_MULT) { spawnTimerMultiplier /= amount; }
        else if (upgradeName == UpgradeType::BALL_COUNT_ADD) { bonusBallCount += amount; }
        else if (upgradeName == UpgradeType::BALL_COUNT_MULT) { bonusBallCountMultiplier *= amount; }
    }

    int bonusBallCount = 0;
    float bonusBallCountMultiplier = 1.0f;
    float speedMultiplier = 1.0f;
    float speedBonus = 0.0f;
    float lifetimeMultiplier = 1.0f;
    float lifetimeBonus = 0.0f;
    float spawnTimerMultiplier = 1.0f;
    float spawnTimerBonus = 0.0f;
};