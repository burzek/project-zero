/*
 * pingpong.cpp
 *
 *  Created on: 5. 3. 2021
 *      Author: boris
 */

#include "game.h"


int main(int argc, char **argv) {
	Uint32 last_tick;
	
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Starting game...");

	Game* game = new Game();
	game->Start();

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Entering main loop...");

	while (game->IsActive()) {
		Uint32 tick = SDL_GetTicks();
		if (tick < last_tick) {
			//too fast
			continue;
		}

		game->HandleInputs();
		while (tick > last_tick) {
			game->UpdateWorld();
			last_tick += 1000 / FPS;
		}
		game->RenderWorld();
	}

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shutting down...");
	game->Shutdown();

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bye bye....");
	return 0;
}



