#include "includes/sprites/newgun.h"

NewGun::NewGun(const Renderer* renderer) : Sprite(renderer)
{
}

NewGun::~NewGun()
{
}

SpriteId NewGun::GetSpriteId() const
{
    return NEW_GUN_ICON;
}

void NewGun::Initialize()
{
    Sprite::LoadTextureSheet("resources/newgun.png", 12, 0);
    sprite_data->sprite_position.x = 500;
    sprite_data->sprite_position.y = 200;
}

void NewGun::UpdateState()
{
    sprite_data->sprite_position.y += 4;
    if (sprite_data->sprite_position.y < 0)
    {

    }
}


void NewGun::Render()
{
    Sprite::Render();
}

int NewGun::GetAnimationSpeed() const
{
    return 30;
}

