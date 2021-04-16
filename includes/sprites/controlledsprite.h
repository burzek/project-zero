#ifndef CONTROLLEDSPRITE_H
#define CONTROLLEDSPRITE_H

#include "sprite.h" 
#include "../input.h"
#include "../constants.h"
#include <SDL2/SDL.h>

class ControlledSprite : public Sprite
{
	public:
		ControlledSprite(const Renderer* renderer);
		virtual ~ControlledSprite();
		void UpdateState();
		virtual void UpdateState(InputManager* input_manager) = 0;
};

#endif /* CONTROLLEDSPRITE_H */
