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
    sprite_data->sprite_position.x = RandRangeInt(150, SCREEN_WIDTH - 150);
    sprite_data->sprite_position.y = SCREEN_HEIGHT - sprite_data->sprite_size.h - 20;
    speed = 0;
    frame_movement_counter = 0;

    current_weapon = new PlasmaGun(renderer, static_cast<Player*>(this));
}

void Player::UpdateState(InputManager *input_manager)
{
    //movement
    if (input_manager->IsLeft())
    {
        sprite_data->sprite_position.x -= ACCELERATE;
        if (++frame_movement_counter % 5 == 0)
        {
            sprite_data->current_sheet_index--;
        }
    }
    else if (input_manager->IsRight())
    {
        sprite_data->sprite_position.x += ACCELERATE;
        if (++frame_movement_counter % 5 == 0)
        {
            sprite_data->current_sheet_index++;
        }
    }
    else
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

    //sheet positon fix
    if (sprite_data->current_sheet_index < 0)
    {
        sprite_data->current_sheet_index = 0;
    }
    else if (sprite_data->current_sheet_index >= sprite_data->sprites_in_sheet)
    {
        sprite_data->current_sheet_index = sprite_data->sprites_in_sheet - 1;
    }


    sprite_data->sprite_position.x  = sprite_data->sprite_position.x < 0 ? 0 : sprite_data->sprite_position.x;
    sprite_data->sprite_position.x = sprite_data->sprite_position.x >= SCREEN_WIDTH - sprite_data->sprite_size.w ? SCREEN_WIDTH - sprite_data->sprite_size.w : sprite_data->sprite_position.x;
}

void Player::Render() {
    Sprite::Render();
    current_weapon->RenderBullets();
}

SpriteId Player::GetSpriteId()
{
	return PLAYER;
}
