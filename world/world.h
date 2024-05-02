#ifndef WORLD_INCLUDED
#define WORLD_INCLUDED

typedef unsigned char TerrainData[64][64];
extern TerrainData terrainData;

void World_init();

#endif