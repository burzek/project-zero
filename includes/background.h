#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "math.h"

#define MAX_STARS 100
#define PLANES 3


struct Star {
    int x,y;
    int plane;
    int speed;
};


class Background {
    public: 
        Background(const Renderer* renderer);
        virtual ~Background();
        void Initialize();
        void Update();
        void Render();
    private:
        Star stars[MAX_STARS];
        const Renderer* renderer;
        SDL_Texture* nebula_texture;
};

#endif // __BACKGROUND_H__