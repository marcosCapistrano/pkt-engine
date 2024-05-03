#include "player.h"

#include "raylib.h"
#include "raymath.h"

#define PLAYER_SPEED 100

Player player;

void Player_init() {
    player.position.x = 0;
    player.position.y = 0;

    player.speed.x = 0;
    player.speed.y = 0;
}

void Player_update(float deltaTime) {
    if (IsKeyDown(KEY_LEFT)) {
        player.position.x -= PLAYER_SPEED * deltaTime;
        player.orientation = 3;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player.position.x += PLAYER_SPEED * deltaTime;

        player.orientation = 1;
    }

    if (IsKeyDown(KEY_UP)) {
        player.position.y -= PLAYER_SPEED * deltaTime;
        player.orientation = 2;
    }
    if (IsKeyDown(KEY_DOWN)) {
        player.position.y += PLAYER_SPEED * deltaTime;
        player.orientation = 0;
    }
}

void Player_render() {
    DrawRectangle(player.position.x, player.position.y, 20, 20, RED);
}

Vector2 Player_position() {
    return player.position;
}