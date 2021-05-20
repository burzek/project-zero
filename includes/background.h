#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "levelmanager.h"
#include "constants.h"
#include "math.h"
#include "gamelevel.h"
#include "sprites/tile.h"

#define MAX_STARS 100
#define PLANES 3


struct Star {
    int x,y;
    int plane;
    int speed;
};


class Background {
    public:
        Background(const Renderer* renderer, const LevelManager* level_manager);
        virtual ~Background();
        void Initialize();
        void Update();
        void Render();
    private:
        Star stars[MAX_STARS];
        const Renderer* renderer;
        const LevelManager* level_manager;
        SDL_Texture* nebula_texture;
        Tile* tiles;
};

#endif // __BACKGROUND_H__
