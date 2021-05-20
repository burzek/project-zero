#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include "gamelevel.h"
#include "common.h"
#include "tile.h"

class LevelManager
{
    public:
        LevelManager();
        virtual ~LevelManager();
        void LoadLevels();
        void SetCurrentLevel(LevelId level_id);
        GameLevel* GetCurrentLevel() const;
    protected:

    private:
        void LoadLevelData(std::string level_descriptor);
        LevelId ToLevelId(std::string levelIdStr) const;
        void ParseTilesData(std::string intArray, std::vector<Tile> tiles);
        std::map<LevelId, GameLevel*>* level_map;
        GameLevel* current_game_level;
};

#endif // LEVELMANAGER_H
