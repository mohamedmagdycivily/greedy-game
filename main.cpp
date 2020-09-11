#include <iostream>
#include "Game.hpp"

int main()
{
    //Initialize random seed
    srand(time(0));
    
    Game game;
    
    while(game.running())
    {
        game.update();
        
        game.render();
    }
    return 0;
}