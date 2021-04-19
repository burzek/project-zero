#include "includes/guns/bullet.h"

Bullet::Bullet(const Renderer* renderer, int init_posx, int init_posy) : Sprite(renderer) {
    this->range = BULLET_RANGE;
    sprite_data->sprite_position.x = init_posx;
    sprite_data->sprite_position.y = init_posy;
}


Bullet::~Bullet() {
}

void Bullet::Initialize() {
    Sprite::LoadTexture("resources/bullet.png");
}


void Bullet::UpdateState() {
    sprite_data->sprite_position.x += BULLET_SPEED;
    range--;
}

bool Bullet::IsOutOfRange() {
    return range <= 0;
}

SpriteId Bullet::GetSpriteId() const {
    return PLASMA_BULLET;
}

