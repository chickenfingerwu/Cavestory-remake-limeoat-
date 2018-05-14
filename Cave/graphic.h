#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED
#include <SDL.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics{
public:
    Graphics();
    ~Graphics();
    SDL_Surface* loadImage(const std::string &filepath);
    void blitSurface(SDL_Texture* source,SDL_Rect* sourceRect,SDL_Rect* destinationRect);
    void flip();
    void clear();
    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::map <std::string,SDL_Surface*>spriteSheet;
};


#endif // GRAPHIC_H_INCLUDED
 
 
