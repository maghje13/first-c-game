#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_ENEMIES 10

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dodge the Enemies Game");
    SetTargetFPS(60);
    srand(time(NULL));  // Seed random number generator

    // Initialize player
    Player player = InitPlayer();

    // Initialize enemies
    Enemy enemies[MAX_ENEMIES];
    int enemyCount = 0;
    int framesCounter = 0;
    
    // Initialize score variable
    int score = 0;
    int scoreTimer = 0;  // Timer to increment score every second

    bool gameOver = false;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game
        if (!gameOver) {
            UpdatePlayer(&player);

            // Spawn new enemies every second (60 frames)
            framesCounter++;
            if (framesCounter % 60 == 0 && enemyCount < MAX_ENEMIES) {
                enemies[enemyCount] = InitEnemy(SCREEN_WIDTH);  // Pass screenWidth to InitEnemy
                enemyCount++;
            }

            // Update enemies and check for collisions
            for (int i = 0; i < enemyCount; i++) {
                UpdateEnemy(&enemies[i], SCREEN_HEIGHT, score);
                if (CheckCollision(player, enemies[i])) {
                    gameOver = true;
                }
            }

            // Update score every second
            scoreTimer++;
            if (scoreTimer % 60 == 0) {
                score++;  // Increment score every second
            }

        } else {
            // Restart game if 'R' is pressed
            if (IsKeyPressed(KEY_R)) {
                player = InitPlayer();
                enemyCount = 0;
                framesCounter = 0;
                score = 0;  // Reset score
                scoreTimer = 0;  // Reset score timer
                gameOver = false;
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (gameOver) {
            DrawText("Game Over!", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 40, RED);
            DrawText("Press R to Restart", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 30, 20, DARKGRAY);

            char scoreText[20];  // Buffer to store the score text
            snprintf(scoreText, sizeof(scoreText), "Score: %d", score);  // Create score text
            DrawText(scoreText, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 50, 20, DARKGREEN);  // Display score at position (10, 10)
        } else {
            DrawRectangleRec(player.rect, player.color);
            for (int i = 0; i < enemyCount; i++) {
                DrawRectangleRec(enemies[i].rect, enemies[i].color);
            }

            // Draw the score at the top-left corner
            char scoreText[20];  // Buffer to store the score text
            snprintf(scoreText, sizeof(scoreText), "Score: %d", score);  // Create score text
            DrawText(scoreText, 10, 10, 20, DARKGREEN);  // Display score at position (10, 10)
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and unload resources
    return 0;
}
