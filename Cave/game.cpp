#include "game.h"
#include <SDL.h>
#include "graphic.h"
#include "input.h"
#include <iostream>
namespace{
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5*1000/FPS;
}

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->Gameloop();
}
Game::~Game()
{

}
void Game::Gameloop()
{
    Graphics graphics;
    SDL_Event event;
    Sprite _player=Sprite(graphics,"content/sprite/MyChar.png",0,0,16,16,100,100);
    Input input;
    int LAST_UPDATE_TIME_MS = SDL_GetTicks();
    while(true)
    {
        input.BeginNewFrame();
        if(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
            {
                if(event.key.repeat==0)
                    input.keyDownEvent(event);
            }
            if(event.type==SDL_KEYUP)
                input.keyUpEvent(event);
            if(event.type==SDL_QUIT)
                return;
        }
        if(input.wasKeyPress(SDL_SCANCODE_ESCAPE)==true)
            return;

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = LAST_UPDATE_TIME_MS - CURRENT_TIME_MS;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME_MS = CURRENT_TIME_MS;
        this->draw(graphics);
    }
}
void Game::draw(Graphics &graphics)
{
    graphics.clear();
    this->_player.draw(graphics,100,100);
    graphics.flip();
}
void Game::update(float elapsed)
{

}
