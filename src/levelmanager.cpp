#include "levelmanager.h"

LevelManager::LevelManager()
{
}

LevelManager::~LevelManager()
{
}


GameLevel* LevelManager::GetLevel(LevelId level_id)
{

}

void LevelManager::LoadLevels()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Reading levels...");
    std::string path = "resources/levels";

    DIR *dir;
    struct dirent *diread;

    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (boost::algorithm::ends_with(diread->d_name, ".lvl")) {
                LoadLevelData(std::string(diread->d_name));
            }
        }
        closedir (dir);

    }
//    ifstream level_file("resources/levels/" + level_description_file);
//    string line;
//
//    while (getline(level_file, line))
//    {
//        ParseId(line);
//        ParseLength(line) ;
//        ParseCeiling(line);
//        ParseFloor(line);
//        ParseEnemies(line);
//    }

}


void LevelManager::LoadLevelData(std::string level_descriptor)
{
    std::fstream level_file(level_descriptor, std::ios::in);
    if (!level_file.is_open()) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Cannot open level file %s", level_descriptor.c_str());
        //todo: what to do
    }
    std::string line;
    while (getline(level_file, line)) {
        std::cout << line;
    }
    level_file.close();
}

