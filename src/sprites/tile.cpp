#include "tile.h"

Tile::Tile(int tile_width, int teil_height, std::string tiles_filename)
{
    this->tile_width = tile_width;
    this->tile_height = tile_height;
    LoadTilesTexture(tiles_filename);
}

Tile::~Tile()
{
}

void Tile::RenderTile(const Renderer* renderer, int tile_index)
{
    SDL_Rect dest_rect {.x = 0, .y = 0, .w = this->tile_width, .h = this->tile_height};
    SDL_Rect src_rect {.x = tile_index * this->tile_width, .y = 0, .w = this->tile_width; .h = this->tile_height};
    SDL_RenderCopy(renderer->sdl_renderer, nebula_texture, &src_rect, &dest_rect);
}

void Tile::LoadTilesTexture(std::string tiles_filename)
{

    tiles_texture = IMG_LoadTexture(renderer->sdl_renderer, tiles_filename);
    if (tiles_texture == nullptr)
    {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Cannot load tiles_texture %s, error: %s", tiles_filename.c_str(), SDL_GetError());
    }

}
