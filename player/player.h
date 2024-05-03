#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "raylib.h"
#include "raymath.h"

typedef struct Player {
    Vector2 position;
    Vector2 speed;

    int orientation;
} Player;

extern Player player;

void Player_init();
void Player_update(float deltaTime);
void Player_render();
Vector2 Player_position();

#endif