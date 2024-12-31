#include "ball.h"
#include "raymath.h"

Ball::Ball() {
    this->x = 0;
    this->y = 0;
    this->radius = BALL_RADIUS;
    this->velocity = {1.0f, -1.0f};
}

Ball::Ball(int x, int y) {
    this->x = x;
    this->y = y;
    this->radius = 8;
    this->velocity = {1.0f, -1.0f};
}

void Ball::draw() {
    DrawCircle(this->x, this->y, this->radius, NEON_RED);
}

void Ball::update(float speed, Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X]) {
    move(speed);
    checkCollision(block, speed);
}

void Ball::move(float speed)
{
    Vector2 v = this->velocity * speed;

    this->x += v.x;
    this->y += v.y;
}

void Ball::checkCollision(Block block[BLOCK_COUNT_Y][BLOCK_COUNT_X], float speed) {
    // Check collision with sides of window
    if (this->x - this->radius <= 0) {
        this->velocity.x = -this->velocity.x;
    } else if (this->x + this->radius >= GetScreenWidth()) {
        this->velocity.x = -this->velocity.x;
    }

    if (this->y - this->radius <= 0) {
        this->velocity.y = -this->velocity.y;
    } else if (this->y + this->radius >= GetScreenHeight()) {
        this->velocity.y = -this->velocity.y;
    }

    for (int i = 0; i < BLOCK_COUNT_Y; i++) {
        for (int j = 0; j < BLOCK_COUNT_X; j++) {
            if (block[i][j].isDestroyed) continue;

            if (this->x >= block[i][j].bounds.x && this->x <= block[i][j].bounds.x + block[i][j].bounds.width) {
                float vCollisionMargin = speed * 1.1f;

                // Brick bottom edge and ball top edge
                if ((this->y - this->radius - block[i][j].bounds.y - block[i][j].bounds.height) <= vCollisionMargin && (this->y - this->radius - block[i][j].bounds.y - block[i][j].bounds.height) >= 0) {
                    this->velocity.y = -this->velocity.y;
                    block[i][j].hit();
                    continue;
                } else if ((this->y + this->radius - block[i][j].bounds.y) >= -vCollisionMargin && (this->y + this->radius - block[i][j].bounds.y <= 0)) {
                    // Brick top edge and ball bottom edge
                    this->velocity.y = -this->velocity.y;
                    block[i][j].hit();
                    continue;
                }
            }

            if (this->y >= block[i][j].bounds.y && this->y <= block[i][j].bounds.y + block[i][j].bounds.height) {
                float hCollisionMargin = speed * 0.8f;

                // Brick right edge and ball left edge
                if ((this->x - this->radius - block[i][j].bounds.x - block[i][j].bounds.width) <= hCollisionMargin && (this->x - this->radius - block[i][j].bounds.x - block[i][j].bounds.width) >= 0) {
                    this->velocity.x = -this->velocity.x;
                    block[i][j].hit();
                    continue;
                } else if ((this->x + this->radius - block[i][j].bounds.x) >= -hCollisionMargin && (this->x + this->radius - block[i][j].bounds.x <= 0)) {
                    // Brick left edge and ball right edge
                    this->velocity.x = -this->velocity.x;
                    block[i][j].hit();
                    continue;
                }
            }
        }
    }
}
