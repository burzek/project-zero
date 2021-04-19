/*
 * game.h
 *
 *  Created on: 5. 3. 2021
 *      Author: boris
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <vector>
#include "scene.h"
#include "sprites/player.h"
#include "sprites/crow.h"
#include "sprites/newgun.h"
#include "background.h"
#include "guns/plasmagun.h"

class Game {
public:
	Game();
	virtual ~Game();
	void Start();
	void Shutdown();
	void HandleInputs();
	void UpdateWorld();
	void RenderWorld();
	bool IsActive() const;
private:
	bool is_active;
	Scene* scene = nullptr;
	InputManager* input_manager  = nullptr;
	Uint32 update_world_time;

	//game objects
	Player* player = nullptr;
	Crow* crow = nullptr;
	Background* background = nullptr;
	NewGun* new_gun = nullptr;
};

#endif /* SRC_GAME_H_ */
