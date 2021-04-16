/*
 * scene.h
 *
 *  Created on: 5. 3. 2021
 *      Author: boris
 */

#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "sprites/sprite.h"
#include "constants.h"
#include "input.h"




class Scene {
public:
	Scene();
	virtual ~Scene();
	void InitializeScene();
	void StartSceneRender();
	void CommitSceneRender();
	Renderer* GetRenderer() const;
private:
	Renderer* renderer = nullptr;
};

#endif /* SRC_SCENE_H_ */
