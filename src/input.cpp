/*
 * input.cpp
 *
 *  Created on: 14. 3. 2021
 *      Author: boris
 */

#include "input.h"
#include <set>

#include <iostream>

InputManager::InputManager()
{
    key_down_map = new std::set<SDL_Scancode>();
}

InputManager::~InputManager()
{
    delete key_down_map;
}

void InputManager::ProcessKeyEvent(SDL_KeyboardEvent *sdl_keyevent)
{
    if (sdl_keyevent->repeat == 0)
    {
        if (sdl_keyevent->type == SDL_KEYDOWN)
        {
            any_key_pressed = true;
            key_down_map->insert(sdl_keyevent->keysym.scancode);
        }
        else if (sdl_keyevent->type == SDL_KEYUP)
        {
            any_key_pressed = false;
            key_down_map->erase(sdl_keyevent->keysym.scancode);
        }
    }
}

bool InputManager::IsUp()
{
    return IsPressed(SDL_SCANCODE_UP);
}

bool InputManager::IsDown()
{
    return IsPressed(SDL_SCANCODE_DOWN);
}

bool InputManager::IsLeft()
{
    return IsPressed(SDL_SCANCODE_LEFT);
}
bool InputManager::IsRight()
{
    return IsPressed(SDL_SCANCODE_RIGHT);
}
bool InputManager::IsSpace()
{
    return IsPressed(SDL_SCANCODE_SPACE);
}

bool InputManager::IsPressed(SDL_Scancode sdl_scancode)
{
    return key_down_map != nullptr && key_down_map->find(sdl_scancode) != key_down_map->end();
}

bool InputManager::IsAnyKeyPressed() {
    return any_key_pressed;
}