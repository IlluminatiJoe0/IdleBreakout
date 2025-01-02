#pragma once

#include <random>
#include <math.h>
#include "raymath.h"

static std::mt19937 gen(std::random_device{}());

inline float getRandomNumber(float min, float max) {
    std::uniform_real_distribution<double> dist(min, max);

    return (float)dist(gen);
}

// Generate a random direction as a unit vector
inline Vector2 getRandomDirection() {
    static std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * PI); // 0 to 2π radians
    float angle = angleDist(gen);

    // Convert angle to unit vector (x = cos(angle), y = sin(angle))
    return { std::cos(angle), std::sin(angle) };
}

inline float randomFloat(float min, float max) { 
    return ((float)rand() / RAND_MAX) * (max - min) + min; 
}
