#ifndef __CROW_H__
#define __CROW_H__

#include "sprite.h"
#include "../constants.h"
#include "../math.h"
#include "../common.h"

class Crow : public Sprite
{
    private:
        int movement_frame_counter;
        int speed;
    public:
        Crow(const Renderer* renderer);
        ~Crow();
        void Render();
        void UpdateState();
        void Initialize();
        SpriteId GetSpriteId() const;

};

#endif // __CROW_H__
