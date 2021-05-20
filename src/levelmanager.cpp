#include "levelmanager.h"
using namespace std;

LevelManager::LevelManager()
{
    level_map = new map<LevelId, GameLevel*>();
}

LevelManager::~LevelManager()
{
}


GameLevel* LevelManager::GetCurrentLevel() const
{
    return this->current_game_level;
}


void LevelManager::SetCurrentLevel(LevelId level_id)
{
    map<LevelId, GameLevel*>::iterator it = level_map->begin();
    while (it != level_map->end()) {
        if (it->first == level_id) {
            current_game_level = it->second;
            return;
        }
        it++;
    }

     throw std::invalid_argument("Invalid LevelId provided, no such level exists:" + level_id);

}


void LevelManager::LoadLevels()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Reading levels...");
    //string path = "resources/levels";

    DIR *dir;
    struct dirent *diread;

    if ((dir = opendir(LEVEL_PATH)) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (boost::algorithm::ends_with(diread->d_name, ".lvl")) {
                LoadLevelData(diread->d_name);
            }
        }
        closedir (dir);

    }

}


void LevelManager::LoadLevelData(string level_descriptor)
{
    string full_path;
    full_path.append(LEVEL_PATH).append("/").append(level_descriptor);

    fstream level_file(full_path, ios::in);
    if (!level_file.is_open()) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Cannot open level file %s", level_descriptor.c_str());
        //todo: what to do
    }

    string line;
    while (getline(level_file, line)) {
        LevelId level_id;
        int level_length;
        vector<int> ceiling_tiles;
        vector<int> floor_tiles;
        vector<int> enemies;

        GameLevel* game_level = {};
        if (boost::algorithm::starts_with(line, "id:")) {
            level_id = ToLevelId(line.substr(3));
        } else if (boost::algorithm::starts_with(line, "length:")) {
            level_length = atoi(line.substr(7).c_str());
        } else if (boost::algorithm::starts_with(line, "ceiling:")) {
            ParseTilesData(line.substr(8), game_level->ceiling_tiles);
        } else if (boost::algorithm::starts_with(line, "floor:")) {
            ParseTilesData(line.substr(6), game_level->floor_tiles);
        } else if (boost::algorithm::starts_with(line, "enemies:")) {
            //todo
        }

//        GameLevel* game_level = new  GameLevel{level_id, level_length, ceiling_tiles, floor_tiles};
        this->level_map->insert(pair<LevelId, GameLevel*>(level_id, game_level));



    }
    level_file.close();
}


LevelId LevelManager::ToLevelId(string levelIdStr) const
{
    if (boost::iequals(levelIdStr, "INTRO"))
    {
        return LevelId::INTRO;
    }
}

void LevelManager::ParseTilesData(string intArray, vector<Tile> tiles)
{
    tiles.
    if (!intArray.empty())
    {
        int pos = intArray.find("|");
        string sizeStr = intArray.substr(0, pos);
        string tilesStr = intArray.substr(pos + 1);

        //parse tile size
        pos = sizeStr.find("x");
        int tileW = atoi(sizeStr.substr(0, pos).c_str());
        int tileH = atoi(sizeStr.substr(pos + 1).c_str());


        //parse tiles indexes
        boost::char_separator<char> sep(",");
        boost::tokenizer<boost::char_separator<char>> tokens(tilesStr, sep);
        for (auto& t : tokens)
        {
            int val = atoi(t.c_str());
            vec.push_back(val);
        }
    }



}
