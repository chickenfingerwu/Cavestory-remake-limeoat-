#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "input.h"
#include "Sprite.h"
class Graphics;

class Game{
public:
    Game();
    ~Game();
private:
    Sprite _player;
    void Gameloop();
    void draw(Graphics &graphics);
    void update(float elapsetime);
};

#endif // GAME_H_INCLUDED
