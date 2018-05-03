#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <SDL.h>
#include <map>
class Input{
public:
    void BeginNewFrame();
    void keyUpEvent(const SDL_Event &event);
    void keyDownEvent(const SDL_Event &event);
    bool wasKeyPress(SDL_Scancode key);
    bool wasKeyHeld(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
private:
    std::map<SDL_Scancode,bool> heldKey;
    std::map<SDL_Scancode,bool> pressedKey;
    std::map<SDL_Scancode,bool> releasedKey;
};

#endif // INPUT_H_INCLUDED
