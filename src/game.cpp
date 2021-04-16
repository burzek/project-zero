/*
 * game.cpp
 *
 *  Created on: 5. 3. 2021
 *      Author: boris
 */

#include "game.h"

Game::Game() {
	is_active = false;
}

Game::~Game() {
}

void Game::Start() {
	scene = new Scene();
	scene->InitializeScene();


	player = new Player(const_cast<Renderer*>(scene->GetRenderer()));
	player->Initialize();

	background = new Background(const_cast<Renderer*>(scene->GetRenderer()));
	background->Initialize();

	crow = new Crow(const_cast<Renderer*>(scene->GetRenderer()));
	crow->Initialize();

	input_manager = new InputManager();
	is_active = true;
}

void Game::Shutdown() {
	is_active = false;
	delete background;
	delete player;
	delete crow;
	delete scene;
	delete input_manager;
}

bool Game::IsActive() const {
	return is_active;
}

void Game::UpdateWorld() {
	background->Update();
	player->UpdateState(input_manager);
	crow->UpdateState();
	update_world_time = SDL_GetTicks();
}

void Game::RenderWorld() {
	scene->StartSceneRender();
		background->Render();
		player->Render();
		crow->Render();
	scene->CommitSceneRender();
}

void Game::HandleInputs() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			is_active = false;
		} else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
			if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				is_active = false;
				break;
			}
			input_manager->ProcessKeyEvent(&event.key);
		}
	}
}
