#ifndef __INPUT_H__
#define __INPUT_H__

#include <SDL2/SDL.h>
#include <set>

class InputManager {
    private:
        std::set<SDL_Scancode>* key_down_map;
        bool any_key_pressed;
    public:
        InputManager();
        virtual ~InputManager();
        void ProcessKeyEvent(SDL_KeyboardEvent* sdl_keyevent);
        bool IsUp();
        bool IsDown();
        bool IsLeft();
        bool IsRight();
        bool IsSpace();
        bool IsPressed(SDL_Scancode sdl_scancode);
        bool IsAnyKeyPressed();
};
#endif // __INPUT_H__