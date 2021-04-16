#include "includes/guns/electro.h"

ElectroGun::ElectroGun(const Renderer *renderer, const Player *player) : Weapon()
{
    this->renderer = renderer;
    this->player = player;
}

ElectroGun::~ElectroGun()
{
}

void ElectroGun::Fire()
{
    if (SDL_GetTicks() - last_fire_time > RECHARGE_TIME_MS)
    {
        GenerateBeam();
        last_fire_time = SDL_GetTicks();
    }
}

bool ElectroGun::IsRecharged()
{
    return SDL_GetTicks() - last_fire_time > RECHARGE_TIME_MS;
}

void ElectroGun::GenerateBeam()
{
    beam_segments.clear();
    SDL_Point init_p = {player->GetSpriteData()->sprite_position.x + RandRangeInt(-20, 20), player->GetSpriteData()->sprite_position.y - GUN_RANGE};
    SDL_Point end_p = {player->GetSpriteData()->sprite_position.x + player->GetSpriteData()->sprite_size.w / 2, (int)player->GetSpriteData()->sprite_position.y};

    beam_segments.push_back(std::make_pair(end_p, init_p));
    int offsetAmount = 35;
    for (int gen = 0; gen < 5; gen++)
    {
        std::vector<std::pair<SDL_Point, SDL_Point>> new_segments;

        for (auto s = beam_segments.begin(); s != beam_segments.end(); s++)
        {
            SDL_Point mid_point = {(s->second.x + s->first.x) / 2, (s->second.y + s->first.y) / 2};
            mid_point.x += RandRangeInt(-offsetAmount, offsetAmount);
            new_segments.push_back(std::make_pair(s->first, mid_point));
            new_segments.push_back(std::make_pair(mid_point, s->second));
        }
        //remove old
        beam_segments = new_segments;
        offsetAmount /= 2;
    }
}

void ElectroGun::RenderBullets()
{
    Uint32 beam_duration = SDL_GetTicks() - last_fire_time;

    int dampening_factor;
    if (beam_duration < 100)
    {
        dampening_factor = 1;
    }
    else if (beam_duration > 100 && beam_duration < 200)
    {
        dampening_factor = 2;
    }
    else if (beam_duration > 200 && beam_duration < 300)
    {
        dampening_factor = 4;
    }
    else if (beam_duration > 300 && beam_duration < 400)
    {
        dampening_factor = 6;
    }
    else
    {
        dampening_factor = 1000;
    }
    int alpha_a = 30 / dampening_factor;
    int alpha_b = 60 / dampening_factor;
    int alpha_c = 255 / dampening_factor;

    SDL_SetRenderDrawBlendMode(this->renderer->sdl_renderer, SDL_BLENDMODE_BLEND);
    float seg_dampening = 1.0;
    for (auto it = beam_segments.begin(); it != beam_segments.end(); it++)
    {
        thickLineRGBA(this->renderer->sdl_renderer, it->first.x, it->first.y, it->second.x, it->second.y, 10,
                      255, 255, 0, alpha_a / seg_dampening);
        thickLineRGBA(this->renderer->sdl_renderer, it->first.x, it->first.y, it->second.x, it->second.y, 5,
                      255, 255, 0, alpha_b / seg_dampening);
        thickLineRGBA(this->renderer->sdl_renderer, it->first.x, it->first.y, it->second.x, it->second.y, 1,
                      255, 255, 255, alpha_c / seg_dampening);
        seg_dampening += 0.1;
    }
}
