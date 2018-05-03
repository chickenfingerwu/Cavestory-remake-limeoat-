#include "input.h"

//get called at begin of new frame to reset keys//
void Input::BeginNewFrame()
{
    this->pressedKey.clear();
    this->releasedKey.clear();
}
void Input::keyDownEvent(const SDL_Event& event)
{
    this->pressedKey[event.key.keysym.scancode] = true;
    this->heldKey[event.key.keysym.scancode] = true;
}
void Input::keyUpEvent(const SDL_Event& event)
{
    this->releasedKey[event.key.keysym.scancode] = true;
    this->heldKey[event.key.keysym.scancode] = false;
}
bool Input::wasKeyPress(SDL_Scancode key)
{
    return this->pressedKey[key];
}
bool Input::wasKeyHeld(SDL_Scancode key)
{
    return this->heldKey[key];
}
bool Input::wasKeyReleased(SDL_Scancode key)
{
    return this->releasedKey[key];
}
