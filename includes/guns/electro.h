#ifndef __ELECTRO_H__
#define __ELECTRO_H__

#define GUN_RANGE 250
#define RECHARGE 2.0

#include <vector>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "weapon.h"
#include "../sprites/player.h"
#include "../constants.h"

class Player;
class ElectroGun : public Weapon {
    public:
        ElectroGun(const Renderer* renderer, const Player* player);
        virtual ~ElectroGun();
        void Fire();
        bool IsRecharged();
        void RenderBullets();
    private:
        void GenerateBeam();
        std::vector<std::pair<SDL_Point, SDL_Point>> beam_segments;
        
        Uint32 last_fire_time;
        const Renderer* renderer = nullptr;
        const Player* player = nullptr;
};

#endif // __ELECTRO_H__