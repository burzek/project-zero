#ifndef NEWGUN_H_INCLUDED
#define NEWGUN_H_INCLUDED

#include "sprite.h"
#include "../constants.h"
#include "../common.h"

class NewGun : public Sprite
{
    public:
        NewGun(const Renderer* renderer);
        virtual ~NewGun();
        GunId GetGunId() const;
        SpriteId GetSpriteId() const;
        void UpdateState();
        void Initialize();
        void Render();
        int GetAnimationSpeed() const;
    private:
        GunId gun_id;


};


#endif // NEWGUN_H_INCLUDED
