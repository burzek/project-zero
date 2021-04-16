/*
 * sprite.cpp
 *
 *  Created on: 6. 3. 2021
 *      Author: boris
 */

#include "includes/sprites/sprite.h"

Sprite::Sprite(const Renderer *renderer)
{
    this->renderer = renderer;
    this->sprite_data = new SpriteData();
}

Sprite::~Sprite()
{
}


void Sprite::LoadTexture(const std::string texture_name)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG, "Loading texture %s", texture_name.c_str());

    sprite_data->sdl_texture = IMG_LoadTexture(renderer->sdl_renderer, texture_name.c_str());
    if (sprite_data->sdl_texture == nullptr)
    {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Cannot load sprite texture: %s", SDL_GetError());
    }

    //process texture
    SDL_Rect rect {.x = 0, .y = 0};
    SDL_QueryTexture(sprite_data->sdl_texture, nullptr, nullptr, &rect.w, &rect.h);

    sprite_data->current_sheet_index = 0;
    sprite_data->sprites_in_sheet = 1;
    sprite_data->sprite_size.w = rect.w;
    sprite_data->sprite_size.h = rect.h;
    sprite_data->sprite_transformation.rotation_degrees = 0;

}


void Sprite::LoadTextureSheet(std::string texture_name, int sprites_in_sheet, int init_sheet_index) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG, "Loading texture sheet %s", texture_name.c_str());

    sprite_data->sdl_texture = IMG_LoadTexture(renderer->sdl_renderer, texture_name.c_str());
    if (sprite_data->sdl_texture == nullptr)
    {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Cannot load sprite sheet texture: %s", SDL_GetError());
    }

    //process texture
    SDL_Rect rect {.x = 0, .y = 0};
    SDL_QueryTexture(sprite_data->sdl_texture, nullptr, nullptr, &rect.w, &rect.h);

    sprite_data->current_sheet_index = init_sheet_index;
    sprite_data->sprites_in_sheet = sprites_in_sheet;
    sprite_data->sprite_size.w = rect.w / sprites_in_sheet;
    sprite_data->sprite_size.h = rect.h;
    sprite_data->sprite_transformation.rotation_degrees = 0;
}


void Sprite::Render()
{
    SDL_Rect src_rect;
    src_rect.x = sprite_data->sprite_size.w * sprite_data->current_sheet_index;
    src_rect.y = 0;
    src_rect.w = sprite_data->sprite_size.w;
    src_rect.h = sprite_data->sprite_size.h;
    SDL_Rect dest_rect;
    dest_rect.x = sprite_data->sprite_position.x;
    dest_rect.y = sprite_data->sprite_position.y;
    dest_rect.w = sprite_data->sprite_size.w;
    dest_rect.h = sprite_data->sprite_size.h;
    SDL_RenderCopy(renderer->sdl_renderer, sprite_data->sdl_texture, &src_rect, &dest_rect);
}

SpriteData *Sprite::GetSpriteData() const
{
    return sprite_data;
}
