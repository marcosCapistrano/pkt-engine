#include "game.h"

#include <stdio.h>

#include "../player/player.h"
#include "../world/world.h"
#include "../render/camera.h"
#include "raylib.h"

const int WindowWidth = 800;
const int WindowHeight = 600;

void Game_init() {
    InitWindow(WindowWidth, WindowHeight, "Poketibia");
    SetTargetFPS(60);

    World_init();
    Camera_init();

    Player_init();
}

void drawChunk() {
    Rectangle source;

    /*
    determine source rectangle from data[i]
    tile number = data[i]
    x = tileNumber%32
    y = tileNumber%32
    */

    /*
     for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; i++) {
         unsigned char tile = data[i];
         int x = (tile % 16) * 32;
         int y = (tile / 16) * 32;
         source.x = (float)x;
         source.y = (float)y;
         source.width = 32;
         source.height = 32;

         Vector2 position = {.x = (i % 32) * 32, .y = (i / 32) * 32};

         DrawTextureRec(spritesheet, source, position, WHITE);
     }
 */
}

void Game_run() {
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        Player_update(deltaTime);

        ClearBackground(BLACK);
        BeginDrawing();
        {
            Camera_draw();
            DrawFPS(10, 10);
        }
        EndDrawing();
    }
}