#include "includes/guns/plasmagun.h"

PlasmaGun::PlasmaGun(const Renderer* renderer, const Player* player) : Weapon() {
    this->renderer = renderer;
    this->player = player;
    bullets = new std::vector<Bullet*>();
}

PlasmaGun::~PlasmaGun() {
    delete bullets;
}

void PlasmaGun::Fire() {
    if (SDL_GetTicks() - last_fire_time > RECHARGE_TIME_MS) {
        //create plasma bullet
        int initx = player->GetSpriteData()->sprite_position.x + player->GetSpriteData()->sprite_size.w - 5;
        int inity = player->GetSpriteData()->sprite_position.y + (player->GetSpriteData()->sprite_size.h / 2) - 5;
        Bullet* b = new Bullet(renderer, initx, inity);
        b->Initialize();
        bullets->push_back(b);
        last_fire_time = SDL_GetTicks();
    }
}

bool PlasmaGun::IsRecharged() {
    return SDL_GetTicks() - last_fire_time > RECHARGE_TIME_MS;
}

void PlasmaGun::RenderBullets() {
    auto it = bullets->begin();
    while (it != bullets->end()) {
        //remove bullet if out of range
        if ((*it)->IsOutOfRange()) {
            it = bullets->erase(it);
        } else {
            (*it)->UpdateState();
            (*it)->Render();
            it++;
        }
    }


}
