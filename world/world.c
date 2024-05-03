/*
    Holds data of the entire world and simulates it
*/
#include "world.h"
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

/* World size in number of tiles */
#define WORLD_SIZE_HOR 64
#define WORLD_SIZE_VER 64

TerrainData terrainData;
CreatureData creatureData;

void loadTerrainData() {
    FILE *map;
    map = fopen("./resources/data/map.pk", "r");

    if (map != NULL) {
        printf("could open\n");
    } else {
        printf("could not open\n");
    }

    int x = 0, y = 0;
    int number;
    while ((fscanf(map, "%d", &number)) != EOF) {
        terrainData[x][y] = number;
        
        x++;
        if (x>WORLD_SIZE_HOR-1) {
            x = 0;
            y+=1; 
        }

        // Leaves the loop if trying to read more than fits the array
        if(y > WORLD_SIZE_VER-1)
            break;
    }

    fclose(map);
}

void exampleAI(Creature *this, float deltaTime) {
    this->position.x += 5*deltaTime;
}

void World_init() {
    loadTerrainData();

    creatureData[0].type = 0;
    creatureData[0].position = (Vector2){0};
}

void World_update(float deltaTime) {
}