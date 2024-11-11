#pragma once

#include "raylib.h"
#include "player.h"

// Define the Enemy struct
typedef struct Enemy {
    Rectangle rect;
    Color color;
} Enemy;

// Initialize an enemy at a random x-position above the screen
Enemy InitEnemy(int screenWidth);

// Update the enemy position (move it downward)
void UpdateEnemy(Enemy *enemy, int screenHeight, int score);

// Check for collision between player and enemy
bool CheckCollision(Player player, Enemy enemy);

