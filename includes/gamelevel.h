#ifndef GAMELEVEL_H
#define GAMELEVEL_H


#include "common.h"
#include "tile.h"
#include <vector>
#include <string>

using namespace std;
struct GameLevel
{
    LevelId level_id;
    int level_length;
    string tile_filename;
    vector<Tile> ceiling_tiles;
    vector<Tile> floor_tiles;
    vector<int> enemies;
    int frame_counter;
};

#endif // GAMELEVEL_H
