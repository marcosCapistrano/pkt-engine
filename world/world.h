#ifndef WORLD_INCLUDED
#define WORLD_INCLUDED

#include "raylib.h"
#include "raymath.h"

#define MAX_CREATURES 256

typedef unsigned char TerrainData[64][64];
extern TerrainData terrainData;

typedef struct Creature {
    unsigned char type;
    Vector2 position;
} Creature;

typedef Creature CreatureData[MAX_CREATURES];
extern CreatureData creatureData;

void World_init();
void World_update(float deltaTime);

#endif