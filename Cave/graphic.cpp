#include <SDL.h>
#include "graphic.h"
#include <SDL_image.h>
#include <iostream>
Graphics::Graphics(){
    SDL_CreateWindowAndRenderer(640,480,0,&_window,&_renderer);
    SDL_SetWindowTitle(this->_window,"cavestoy");
}
Graphics::~Graphics(){
    SDL_DestroyWindow(this->_window);
}
SDL_Surface* Graphics::loadImage(const std::string &filepath)
{
    if(this->spriteSheet.count(filepath)==0)
    {
        this->spriteSheet[filepath]=IMG_Load(filepath.c_str());
    }
    return this->spriteSheet[filepath];
}
void Graphics::blitSurface(SDL_Texture* texture,SDL_Rect* sourceRect,SDL_Rect* destinationRect)
{
    SDL_RenderCopy(this->_renderer,texture,sourceRect,destinationRect);
}
void Graphics::flip()
{
    SDL_RenderPresent(this->_renderer);
}
void Graphics::clear()
{
    SDL_RenderClear(this->_renderer);
}
SDL_Renderer* Graphics::getRenderer() const
{
    return this->_renderer;
}
