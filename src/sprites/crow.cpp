#include "includes/sprites/crow.h"


Crow::Crow(const Renderer* renderer)  : Sprite(renderer)
{
}

Crow::~Crow()
{

}

void Crow::Render()
{
    Sprite::Render();
//    if (SDL_GetTicks() % 10 == 0)
//    {
//        sprite_data->current_sheet_index++;
//        if (sprite_data->current_sheet_index == sprite_data->sprites_in_sheet) {
//            sprite_data->current_sheet_index = 0;
//        }
//
//    }
//
}

void Crow::UpdateState()
{

    if (sprite_data->sprite_position.x > (SCREEN_WIDTH - sprite_data->sprite_size.w - 20) ||
        sprite_data->sprite_position.x < sprite_data->sprite_size.w) {
            speed *= -1;
    }
    sprite_data->sprite_position.y = 150 + 100 * sin(2 * movement_frame_counter * M_PI / 180.0);
    sprite_data->sprite_position.x += speed;

    movement_frame_counter++;
}

void Crow::Initialize()
{
    Sprite::LoadTextureSheet("resources/crow.png", 16, 0);
    sprite_data->sprite_position.x = sprite_data->sprite_size.w + 20;
    sprite_data->sprite_position.y = SCREEN_HEIGHT / 2;
    movement_frame_counter = 0;
    speed = 4;
}

SpriteId Crow::GetSpriteId() const
{
	return CROW;
}
