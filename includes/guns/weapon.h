#ifndef __PLAYERWEAPON_H__
#define __PLAYERWEAPON_H__

class Weapon {
    public : 
        Weapon();
        virtual ~Weapon();
        virtual void Fire() = 0;
        virtual bool IsRecharged() = 0;
        virtual void RenderBullets() = 0;
};

#endif // __PLAYERWEAPON_H__