/*
 * Player.cpp
 *
 *  Created on: 11. 3. 2021
 *      Author: boris
 */
#include "includes/sprites/player.h"

Player::Player(const Renderer *renderer) : ControlledSprite(renderer)
{
}

Player::~Player()
{
    delete current_weapon;
}

void Player::Initialize()
{
    Sprite::LoadTextureSheet("resources/player.png", 11, 5);
    sprite_data->sprite_position.x = 20;
    sprite_data->sprite_position.y = SCREEN_HEIGHT / 2;
    speed = 0;
    frame_movement_counter = 0;
    sprite_data->sprite_transformation.rotation_degrees = 90;
    current_weapon = new PlasmaGun(renderer, static_cast<Player*>(this));
}

void Player::UpdateState(InputManager *input_manager)
{
    //movement
    if (input_manager->IsUp())
    {
        sprite_data->sprite_position.y -= ACCELERATE;
        if (++frame_movement_counter % 5 == 0)
        {
            sprite_data->current_sheet_index = std::max(sprite_data->current_sheet_index - 1 , 0);
        }
    }

    if (input_manager->IsDown())
    {
        sprite_data->sprite_position.y += ACCELERATE;
        if (++frame_movement_counter % 5 == 0)
        {
            sprite_data->current_sheet_index = std::min(sprite_data->current_sheet_index + 1, sprite_data->sprites_in_sheet - 1);
        }
    }

    if (input_manager->IsLeft())
    {
        sprite_data->sprite_position.x -= ACCELERATE;
    }

    if (input_manager->IsRight())
    {
        sprite_data->sprite_position.x += ACCELERATE;
    }

    if (!input_manager->IsUp() && !input_manager->IsDown())
    {
        frame_movement_counter = 0;
        sprite_data->current_sheet_index = 5;
    }

    if (input_manager->IsPressed(SDL_SCANCODE_RETURN))
    {
         current_weapon = new ElectroGun (renderer, this);
    }

    if (input_manager->IsSpace() && current_weapon->IsRecharged())
    {
        current_weapon->Fire();
    }

    sprite_data->sprite_position.x  = std::max(0, sprite_data->sprite_position.x);
    sprite_data->sprite_position.x = std::min(sprite_data->sprite_position.x, SCREEN_WIDTH - sprite_data->sprite_size.w);
    sprite_data->sprite_position.y  = std::max(0, sprite_data->sprite_position.y);
    sprite_data->sprite_position.y = std::min(sprite_data->sprite_position.y, SCREEN_HEIGHT- sprite_data->sprite_size.h);
}

void Player::Render()
{
    Sprite::Render();
    current_weapon->RenderBullets();
}

SpriteId Player::GetSpriteId() const
{
	return PLAYER;
}

