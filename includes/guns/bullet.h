#ifndef __BULLET_H__
#define __BULLET_H__

#include <SDL2/SDL.h>
#include "../constants.h"
#include "../input.h"
#include "../sprites/sprite.h"
#include "../common.h"


#define BULLET_SPEED 4
#define BULLET_RANGE 500

class Bullet : public Sprite {
    private:
        float range;
    public:
        Bullet(const Renderer* renderer, int init_posx, int init_posy);
        ~Bullet();
        void UpdateState();
        void Initialize();
        bool IsOutOfRange();
        SpriteId GetSpriteId();



};
#endif // __BULLET_H__