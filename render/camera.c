#include "../game/window.h"
#include "../player/player.h"
#include "../world/world.h"
#include "raylib.h"

Camera2D camera = {0};
Texture2D spritesheet;
Texture2D playerSpritesheet;

/* tile size in pixels */
const int tileSize = 32;

void Camera_init() {
    spritesheet = LoadTexture("./resources/spritesheets/tiles.png");
    playerSpritesheet = LoadTexture("./resources/spritesheets/character.png");

    camera.offset = (Vector2){(WindowWidth / 2.0f) - 16.0f, (WindowHeight / 2.0f) - 32.0f};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    camera.target.x = 0;
    camera.target.y = 0;
}

void drawTiles() {
    int targetTileX = camera.target.x / tileSize;
    int targetTileY = camera.target.y / tileSize;

    Rectangle source = {0};
    source.width = tileSize;
    source.height = tileSize;

    for (int j = targetTileY - 12; j < targetTileY + 12; j++) {
        for (int i = targetTileX - 14; i < targetTileX + 14; i++) {
            unsigned char tileNum = terrainData[i][j];
            if (tileNum == 0) {
                source.x = 32;
                source.y = 0;
            } else {
                source.x = 0;
                source.y = 48 * 32;
            }

            Vector2 dest = {.x = i * 32, .y = j * 32};
            DrawTextureRec(spritesheet, source, dest, WHITE);
        }
    }
}

void drawCreatures() {
    int targetTileX = camera.target.x / tileSize;
    int targetTileY = camera.target.y / tileSize;

    for (int i = 0; i < MAX_CREATURES; i++) {
        Creature curr = creatureData[i];

        if (curr.position.x > (targetTileX - 14) * 32 && curr.position.x < (targetTileX + 14) * 32) {
            if (curr.position.y > (targetTileY - 10) * 32 && curr.position.y < (targetTileY + 10) * 32) {
                DrawRectangle(curr.position.x, curr.position.y, 32, 32, RED);
            }
        }
    }
}

int currentFrame = 0;
int framesCounter = 0;
int framesSpeed = 6;

Rectangle frameRec = {0.0f, 0.0f, 16.0f, 32.0f};
void drawPlayer() {
    frameRec.y = player.orientation*32.0f;
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) currentFrame = 0;

        frameRec.x = (float)currentFrame * 16.0f;
    }

    DrawTextureRec(playerSpritesheet, frameRec, player.position, WHITE);
}

void Camera_update() {
    camera.target = player.position;
}

void Camera_draw() {
    BeginMode2D(camera);
    {
        drawTiles();
        drawCreatures();
        drawPlayer();
    }
    EndMode2D();
}