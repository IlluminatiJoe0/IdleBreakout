#include "ball.h"

Ball::Ball() {
    this->x = 0;
    this->y = 0;
    this->radius = BALL_RADIUS;
    this->angle = 0.0f;
}

Ball::Ball(int x, int y, UpgradeManager* upgradeManager) {
    this->x = x;
    this->y = y;
    this->radius = 8;
    this->angle = randomFloat(0.0f, 8.0f * PI);
    this->upgradeManager = upgradeManager;
}

void Ball::draw() {
    DrawCircle(this->x, this->y, this->radius, NEON_RED);
    
    // DEBUG
    // char buffer[32];
    // sprintf(buffer, "%f, %f", this->direction.x, this->direction.y);
    // int width = MeasureText(buffer, 6);
    // DrawText(buffer, this->x - width / 2, this->y - this->radius * 4, 6, NEON_RED);
}

void Ball::update(float speed, Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]) {
    // Apply speed upgrades
    speed = speed * this->upgradeManager->speedMultiplier + this->upgradeManager->speedBonus;

    move(speed);
    checkCollision(block, speed);
    ensureNonZeroDirection();
}

void Ball::move(float speed) {
    this->x += cos(this->angle) * speed;
    this->y += sin(this->angle) * speed;
}

void Ball::reverseHorizontalDirection() {
    this->angle = PI - this->angle;
}

void Ball::reverseVerticalDirection() {
    this->angle = -this->angle;
}

void Ball::ensureNonZeroDirection() {
    float a = this->angle;
    float minVal = 0.1f;

    // If an angle is too close to one of the cardinal directions, pick a random angle
    if (a <= minVal && angle >= -minVal) {
        this->angle = randomFloat(0.0f, 16.0f * PI);
    } else if (a >= 3*(PI/2) - minVal && angle <= 3*(PI/2) + minVal) {
        this->angle = randomFloat(0.0f, 16.0f * PI);
    } else if (a <= PI/2 - minVal && angle >= PI/2 + minVal) {
        this->angle = randomFloat(0.0f, 16.0f * PI);
    } else if (a >= PI - minVal && angle <= PI + minVal) {
        this->angle = randomFloat(0.0f, 16.0f * PI);
    }
}


void Ball::checkCollision(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X], float speed) {
    // Check collision with sides of window
    // left edge
    if (this->x - this->radius <= GAME_X_OFFSET) {
        reverseHorizontalDirection();
        this->x = this->radius + GAME_X_OFFSET + 4;
        PlaySound(SoundManager::GetInstance().GetSound("border_hit"));
    // right edge
    } else if (this->x + this->radius - GAME_X_OFFSET >= GAME_WIDTH) {
        reverseHorizontalDirection();
        this->x = GAME_X_OFFSET + GAME_WIDTH - this->radius - 4;
        PlaySound(SoundManager::GetInstance().GetSound("border_hit"));
    }

    // Check collision with top and bottom of window
    // Top edge
    if (this->y - this->radius <= GAME_Y_OFFSET) {
        reverseVerticalDirection();
        this->y = this->radius + GAME_Y_OFFSET;
        PlaySound(SoundManager::GetInstance().GetSound("border_hit"));
    // Bottom edge
    } else if (this->y + this->radius - GAME_Y_OFFSET >= GAME_HEIGHT) {
        reverseVerticalDirection();
        this->y = GAME_Y_OFFSET + GAME_HEIGHT - this->radius;
        PlaySound(SoundManager::GetInstance().GetSound("border_hit"));
    }

    // If the ball is below all the blocks, don't check collision
    if (this->y - this->radius - 1 > GAME_Y_OFFSET + (BLOCK_HEIGHT+1) * BLOCK_COUNT_Y) {
        return;
    }
    
    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            if (block[i][j].isDestroyed) continue;

            // Get block bounds
            Rectangle blockBounds = block[i][j].bounds;

            // Check AABB collision
            if (CheckCollisionCircleRec(Vector2{this->x, this->y}, this->radius, blockBounds)) {
                // Determine the side of collision by calculating overlap
                float overlapLeft = (this->x + this->radius) - blockBounds.x;
                float overlapRight = (blockBounds.x + blockBounds.width) - (this->x - this->radius);
                float overlapTop = (this->y + this->radius) - blockBounds.y;
                float overlapBottom = (blockBounds.y + blockBounds.height) - (this->y - this->radius);

                // Find the smallest overlap to determine the collision side
                float minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

                if (minOverlap == overlapLeft) {
                    // Collision on the left
                    reverseHorizontalDirection();
                } else if (minOverlap == overlapRight) {
                    // Collision on the right
                    reverseHorizontalDirection();
                } else if (minOverlap == overlapTop) {
                    // Collision on the top
                    reverseVerticalDirection();
                } else if (minOverlap == overlapBottom) {
                    // Collision on the bottom
                    reverseVerticalDirection();
                }

                // Mark the block as hit
                block[i][j].hit();

                // Break out of loop since one block can only be hit per update
                return;
            }
        }
    }
}
