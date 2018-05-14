//Lưu thông tin của hình muốn vẽ

#include "Sprite.h"
#include "graphic.h"
#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
Sprite::Sprite()
{

}
Sprite::Sprite(Graphics &graphics,const std::string filepath,int sourceX,int sourceY,int width,
       int height,float posX,float posY):_x(posX),_y(posY)
{
    this->_sourceRect.x=sourceX;
    this->_sourceRect.y=sourceY;
    this->_sourceRect.w=width;
    this->_sourceRect.h=height;
    this->_spriteSheet=SDL_CreateTextureFromSurface(graphics.getRenderer(),graphics.loadImage(filepath));
    if(this->_spriteSheet==NULL)
    {
        std::cout<<IMG_GetError();
    }
}
Sprite::~Sprite()
{

}
void Sprite::update()
{

}
void Sprite::draw(Graphics &graphics,int x,int y)
{
    SDL_Rect destinationRect={x,y,this->_sourceRect.w,this->_sourceRect.h};
    graphics.blitSurface(this->_spriteSheet,&this->_sourceRect,&destinationRect);
}
