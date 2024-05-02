#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "raylib.h"
#include "raymath.h"


void Player_init();
void Player_update(float deltaTime);
void Player_render();
Vector2 Player_position();

#endif