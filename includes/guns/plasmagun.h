#ifndef __PLASMAGUN_H__
#define __PLASMAGUN_H__

#include <vector>
#include <SDL2/SDL.h>
#include "bullet.h"
#include "weapon.h"
#include "../sprites/player.h"
#include "../input.h"

class Player;

#define RECHARGE_TIME_MS 250
class PlasmaGun : public Weapon {
    public:
        PlasmaGun(const Renderer* renderer, const Player* player);
        virtual ~PlasmaGun();
        void Fire();
        bool IsRecharged();
        void RenderBullets();
    private:
        Uint32 last_fire_time;
        std::vector<Bullet*>* bullets = nullptr;
        const Renderer* renderer = nullptr;
        const Player* player = nullptr;

};
#endif // __PLASMAGUN_H__