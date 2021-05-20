#include "gamelevel.h"

using namespace std;

GameLevel::GameLevel(LevelId level_id, int level_length, std::vector<int> ceiling_tiles, std::vector<int> floor_tiles)
{
    this->level_id = level_id;
    this->level_length = level_length;
    this->ceiling_tiles = ceiling_tiles;
    this->floor_tiles = floor_tiles;
}


GameLevel::~GameLevel()
{
}


const LevelId GameLevel::GetLevelId()
{
    return this->level_id;
}

const int GameLevel::GetLevelLength()
{
    return this->level_length;
}

std::vector<int> GameLevel::GetCeilingTiles()
{
    return this->ceiling_tiles;
}

std::vector<int> GameLevel::GetFloorTiles()
{
    return this->floor_tiles;
}


