#pragma once

// BLOCKS
const int BLOCK_HEIGHT = 15;
const int BLOCK_WIDTH = 39;

const int BLOCK_COUNT_X = 32;
const int BLOCK_COUNT_Y = 16;
const int BLOCK_COUNT = BLOCK_COUNT_X * BLOCK_COUNT_Y;

// COLORS
const Color NEON_GREEN = {15, 255, 80, 255};
const Color DULL_GREEN = {8, 120, 35, 255};
const Color MODERN_BLACK = {14, 14, 16, 255};
const Color NEON_RED = {255, 49, 49, 255};
const Color OLED_BLACK = {0, 0, 0, 255};

// PADDLE
const int PADDLE_HEIGHT = 16;

// WINDOW
const int WINDOW_WIDTH = 1680;
const int WINDOW_HEIGHT = 1000;

const int WINDOW_CENTER_X = WINDOW_WIDTH / 2;
const int WINDOW_CENTER_Y = WINDOW_HEIGHT / 2;

// GAME
const int GAME_CENTER_X = 1280 / 2;
const int GAME_CENTER_Y = 800 / 2;
const int GAME_WIDTH = 1280;
const int GAME_HEIGHT = 800;

const int GAME_X_OFFSET = 40;
const int GAME_Y_OFFSET = 40;

// BALL
const int BALL_RADIUS = 8;
const int BALL_SPAWN_Y = WINDOW_HEIGHT * 0.8;