#pragma once

#include "raylib.h"

typedef struct Player {
    Rectangle rect;
    Color color;
} Player;

// Initialize player with default position and size
Player InitPlayer();

// Update player position based on input
void UpdatePlayer(Player *player);
