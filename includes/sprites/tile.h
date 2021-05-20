#ifndef TILE_H
#define TILE_H


#include <vector>
#include <common.h>
class Tile
{
    public:
        Tile(int tile_width, int tile_height, std::strign tiles_filename);
        virtual ~Tile();
        void RenderTile(const Renderer* renderer, int tile_index);
    private:
        void LoadTilesTexture();
        int tile_width;
        int tile_height;
        SDL_Texture* tiles_texture;
};

#endif // TILE_H
