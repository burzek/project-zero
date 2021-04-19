/*
 * sprite.h
 *
 *  Created on: 6. 3. 2021
 *      Author: boris
 */

#ifndef SRC_SPRITE_H_
#define SRC_SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../constants.h"
#include "../common.h"
#include "../input.h"

struct Transformation {
	int rotation_degrees;
};

struct Position {
	int x;
	int y;
};

struct Size {
	int w;
	int h;
};

struct SpriteData {
	SDL_Texture* sdl_texture;
	Position sprite_position;
	Size sprite_size;
	Transformation sprite_transformation;
	int current_sheet_index;
	int sprites_in_sheet;
};



class Sprite {
	public:
		Sprite(const Renderer* renderer);
		virtual ~Sprite();
		virtual void LoadTexture(std::string texture_name);
		virtual void LoadTextureSheet(std::string texture_name, int sprites_in_sheet, int init_sheet_index);
		virtual void Render();
		virtual void UpdateState() = 0;
		virtual void Initialize() = 0;
		virtual SpriteId GetSpriteId() const = 0;
		SpriteData* GetSpriteData() const;
		virtual int GetAnimationSpeed() const;
	protected:
		const Renderer* renderer = nullptr;
		SpriteData* sprite_data = nullptr;
		int last_sprite_animation_tick;
};

#endif /* SRC_SPRITE_H_ */
