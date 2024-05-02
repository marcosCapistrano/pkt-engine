#include "../world/world.h"
#include "../game/window.h"
#include "raylib.h"

Camera2D camera = {0};
Texture2D spritesheet;

/* tile size in pixels */
const int tileSize = 32;

void Camera_init() {
    spritesheet = LoadTexture("./resources/spritesheets/tiles.png");

    camera.offset = (Vector2){WindowWidth / 2.0f, WindowHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.target.x = 0;
    camera.target.y = 0;
}

void Camera_draw() {
    int targetTileX = camera.target.x / tileSize;
    int targetTileY = camera.target.y / tileSize;

    if (IsKeyDown(KEY_LEFT)) camera.target.x -= 10;
    if (IsKeyDown(KEY_RIGHT)) camera.target.x += 10;

    if (IsKeyDown(KEY_UP)) camera.target.y -= 10;
    if (IsKeyDown(KEY_DOWN)) camera.target.y += 10;

    BeginMode2D(camera);
    {
        Rectangle source = {0};
        source.width = tileSize;
        source.height = tileSize;

        for (int j = targetTileY - 12; j < targetTileY + 12; j++) {
            for (int i = targetTileX - 14; i < targetTileX + 14; i++) {
                unsigned char tileNum = terrainData[i][j];
                if(tileNum == 0) {
                    source.x = 32;
                    source.y = 0;
                } else {
                    source.x = 0;
                    source.y = 48*32;
                }

                Vector2 dest = {.x = i*32, .y=j*32};
                DrawTextureRec(spritesheet, source, dest, WHITE);
            }
        }
    }
    EndMode2D();
}