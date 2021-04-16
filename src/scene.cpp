/*
 * scene.cpp
 *
 *  Created on: 5. 3. 2021
 *      Author: boris
 */

#include "scene.h"

Scene::Scene() {
}

Scene::~Scene() {
	if (renderer->sdl_window != nullptr) {
		SDL_DestroyWindow(renderer->sdl_window);
	}	
	SDL_Quit();
}

void Scene::InitializeScene() {
	renderer = new Renderer();
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "Cannot initialize SDL video: %s", SDL_GetError());
		exit(1);
	}
	renderer->sdl_window = SDL_CreateWindow("AlphaZero", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (renderer->sdl_window == nullptr) {
	    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "Cannot create SDL window: %s", SDL_GetError());
		exit(1);
	}

	renderer->sdl_renderer = SDL_CreateRenderer(renderer->sdl_window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer->sdl_renderer == nullptr) {
	    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "Cannot create SDL renderer: %s", SDL_GetError());
		exit(1);
	}
	
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void Scene::StartSceneRender() {
	SDL_SetRenderDrawColor(renderer->sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer->sdl_renderer);
}

void Scene::CommitSceneRender() {
	 SDL_RenderPresent(renderer->sdl_renderer);
}


Renderer* Scene::GetRenderer() const {
	return renderer;
}
