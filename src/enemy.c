#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

Enemy InitEnemy(int screenWidth) {
    Enemy enemy;
    enemy.rect = (Rectangle) { rand() % (screenWidth - 50), -50, 50, 50 };
    enemy.color = RED;
    return enemy;
}

void UpdateEnemy(Enemy *enemy, int screenHeight, int score) {
    enemy->rect.y += score/5 + 5;
    
    // Reset enemy to the top if it moves off-screen
    if (enemy->rect.y > screenHeight) {
        enemy->rect.y = -enemy->rect.height;
        enemy->rect.x = rand() % (GetScreenWidth() - 50);  // Use screenWidth here
    }
}

bool CheckCollision(Player player, Enemy enemy) {
    return CheckCollisionRecs(player.rect, enemy.rect);
}
