/*
 * constants.h
 *
 *  Created on: 6. 3. 2021
 *      Author: boris
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define FPS 60

typedef struct {
	SDL_Window* sdl_window = nullptr;
	SDL_Renderer* sdl_renderer = nullptr;
} Renderer;

#endif /* SRC_CONSTANTS_H_ */
