#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <SDL2/SDL.h>
#include <map>
#include <dirent.h>
#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include "gamelevel.h"

class LevelManager
{
    public:
        LevelManager();
        virtual ~LevelManager();
        void LoadLevels();
        GameLevel* GetLevel(LevelId level_id);
    protected:

    private:
        void LoadLevelData(std::string level_descriptor);
        std::map<LevelId, GameLevel*>* level_map;
};

#endif // LEVELMANAGER_H
