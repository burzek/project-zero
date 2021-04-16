#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "controlledsprite.h"
#include "../constants.h"
#include "../math.h"
#include "../input.h"
#include "../guns/plasmagun.h"
#include "../guns/electro.h"

#define ACCELERATE 5
#define PI 3.141592f

class PlasmaGun;

class Player : public ControlledSprite {
    private:
        int speed;
        int frame_movement_counter;
        Weapon* current_weapon;

    public:
        Player(const Renderer* renderer);
        ~Player();
        void Render();
        SpriteId GetSpriteId();
        void UpdateState(InputManager* input_manager);
        void Initialize();
};

#endif // __PLAYER_H__
