#include "block.h"

Block::Block() {
    this->x = 0;
    this->y = 0;
}

Block::Block(int x, int y) {
    this->x = x;
    this->y = y;
    this->health = 10;
    this->bounds = Rectangle{(float)(x * (BLOCK_WIDTH + 1)) + GAME_X_OFFSET, (float)(y * (BLOCK_HEIGHT + 1)) + GAME_X_OFFSET, BLOCK_WIDTH, BLOCK_HEIGHT};
}

void Block::draw() {
    if (this->isDestroyed) {
        DrawRectangleLines(this->x * (BLOCK_WIDTH + 1) + GAME_X_OFFSET, this->y * (BLOCK_HEIGHT + 1) + GAME_X_OFFSET, BLOCK_WIDTH, BLOCK_HEIGHT, DULL_GREEN);
        return;
    }

    DrawRectangleLines(this->x * (BLOCK_WIDTH + 1) + GAME_X_OFFSET, this->y * (BLOCK_HEIGHT + 1) + GAME_X_OFFSET, BLOCK_WIDTH, BLOCK_HEIGHT, NEON_GREEN);

    char buffer[10];
    sprintf(buffer, "%d", this->health);
    int width = MeasureText(buffer, 1);

    DrawText(buffer, this->x * (BLOCK_WIDTH + 1) + (BLOCK_WIDTH + 1) / 2 - width / 2 + GAME_X_OFFSET, this->y * (BLOCK_HEIGHT + 1) + (BLOCK_HEIGHT + 1) / 4 + GAME_X_OFFSET, 1, NEON_GREEN);
}

void Block::hit() {
    this->health -= 10;

    PlaySound(SoundManager::GetInstance().GetSound("block_hit"));

    if (this->health <= 0) {
        this->isDestroyed = true;
    }
}

bool Block::checkIsDestroyed() {
    if (this->isDestroyed && !this->isCollected) {
        this->isCollected = true;
        return true;
    }

    return false;
}
