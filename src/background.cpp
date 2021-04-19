#include "background.h"



Background::Background(const Renderer* renderer) {
    this->renderer = renderer;
}


Background::~Background() {

}

void Background::Initialize() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i] = {.x = RandRangeInt(0, SCREEN_WIDTH), .y = RandRangeInt(0, SCREEN_HEIGHT), .plane = RandRangeInt(1, 3), .speed = RandRangeInt(1, 3)};
    }

    //load planet
    nebula_texture = IMG_LoadTexture(renderer->sdl_renderer, "resources/nebula.jpg");
    if (nebula_texture == nullptr)
    {
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Cannot load nebula texture: %s", SDL_GetError());
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
    SDL_Rect dest_rect {.x = 0, .y = 0, .w = SCREEN_WIDTH, .h = SCREEN_HEIGHT};
    SDL_RenderCopy(renderer->sdl_renderer, nebula_texture, nullptr, &dest_rect);

    for (int i = 0; i < MAX_STARS; i++) {
        int color = 255 - (50 * stars[i].plane);
        SDL_SetRenderDrawColor(this->renderer->sdl_renderer, color, color, color, SDL_ALPHA_OPAQUE);
        SDL_Rect rect = {stars[i].x, stars[i].y, 2, 2};
        SDL_RenderDrawRect(this->renderer->sdl_renderer, &rect);
    }
}
