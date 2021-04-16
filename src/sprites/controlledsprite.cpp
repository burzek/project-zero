#include "includes/sprites/controlledsprite.h"

ControlledSprite::ControlledSprite(const Renderer* renderer) : Sprite(renderer)
{
}

ControlledSprite::~ControlledSprite()
{
}

void ControlledSprite::UpdateState()
{
	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Calling UpdateState() method on ControlledSprite instance");
}


