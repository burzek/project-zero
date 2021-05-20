#include "background.h"



Background::Background(const Renderer* renderer, const LevelManager* level_manager) {
    this->renderer = renderer;
    this->level_manager = level_manager;
}


Background::~Background() {

}

void Background::Initialize() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i] = {.x = RandRangeInt(0, SCREEN_WIDTH), .y = RandRangeInt(0, SCREEN_HEIGHT), .plane = RandRangeInt(1, 3), .speed = RandRangeInt(1, 3)};
    }

    //load nebula
    nebula_texture = IMG_LoadTexture(renderer->sdl_renderer, "resources/nebula.jpg");
    if (nebula_texture == nullptr)
    {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Cannot load nebula texture: %s", SDL_GetError());
    }

    //load tiles
    GameLevel* game_level = const_cast<LevelManager*>(level_manager)->GetCurrentLevel();
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Loading tiles for level " + game_level->level_id);
    //95x98
    if (!game_level->floor_tiles.empty()) {
    }
    if (!game_level->ceiling_tiles.empty()) {
    }


}

void Background::Update() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].x -= stars[i].speed;
        if (stars[i].x <= 0) {
            stars[i].x = SCREEN_WIDTH;
        }
    }

}

void Background::Render() {
    //render nebula
    SDL_Rect dest_rect {.x = 0, .y = 0, .w = SCREEN_WIDTH, .h = SCREEN_HEIGHT};
    SDL_RenderCopy(renderer->sdl_renderer, nebula_texture, nullptr, &dest_rect);

    //render stars
    for (int i = 0; i < MAX_STARS; i++) {
        int color = 255 - (50 * stars[i].plane);
        SDL_SetRenderDrawColor(this->renderer->sdl_renderer, color, color, color, SDL_ALPHA_OPAQUE);
        SDL_Rect rect = {stars[i].x, stars[i].y, 2, 2};
        SDL_RenderDrawRect(this->renderer->sdl_renderer, &rect);
    }

    //render tiles

}
