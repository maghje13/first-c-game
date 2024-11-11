#include "player.h"
#include "raylib.h"

Player InitPlayer() {
    Player player;
    player.rect = (Rectangle) { 400, 550, 50, 50 };
    player.color = BLUE;
    return player;
}

void UpdatePlayer(Player *player) {
    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && player->rect.x + player->rect.width < 800) {
        player->rect.x += 8;
    }
    if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && player->rect.x > 0) {
        player->rect.x -= 8;
    }
}
