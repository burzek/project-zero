#include "gamelevel.h"

using namespace std;

GameLevel::GameLevel()
{
}

GameLevel::~GameLevel()
{
}

void GameLevel::LoadLevelDescription(std::string level_description_file)
{
    ifstream level_file("resources/levels/" + level_description_file);
    string line;

    while (getline(level_file, line))
    {
        ParseId(line);
        ParseLength(line) ;
        ParseCeiling(line);
        ParseFloor(line);
        ParseEnemies(line);
    }

}



void GameLevel::ParseId(string line)
{
    level_id = LevelId::INTRO;
    if (line.rfind("id:") == 0)
    {
           if (line.substr(3).compare("INTRO") == 0)
           {
                level_id = LevelId::INTRO;
           }
    }

}

void GameLevel::ParseLength(string line)
{
    if (line.rfind("length:") == 0)
    {
        level_length = atoi(line.substr(8).c_str());
    }
}

void GameLevel::ParseCeiling(string line)
{
    if (line.rfind("ceiling:") == 0)
    {
        //todo
    }
}

void GameLevel::ParseFloor(string line)
{
    if (line.rfind("floor:") == 0)
    {
            line = line.substr(7);
            stringstream ss(line.substr(7));
            string token;
            while (std::getline(ss, token, ',')) {
                cout << "token:" << token << endl;
            }
    }
}

void GameLevel::ParseEnemies(string line)
{
}

