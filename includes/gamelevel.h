#ifndef GAMELEVEL_H
#define GAMELEVEL_H


#include "common.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GameLevel
{
    public:
        GameLevel();
        virtual ~GameLevel();
        void LoadLevelDescription(std::string level_description_file);
    private:
        void ParseId(std::string line);
        void ParseLength(std::string line);
        void ParseCeiling(std::string line);
        void ParseFloor(std::string line);
        void ParseEnemies(std::string line);
        LevelId level_id;
        int level_length;
        int* ceiling_tiles;
        int* floor_tiles;
        int frame_counter;
};

#endif // GAMELEVEL_H
