#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"

class Player
{
private:
    sf::RectangleShape shape;
    int movementSpeed;
    
    void initShape(float x, float y);
    void initVariables();
public:
    Player(float x = 0, float y = 0);
    ~Player();
    
    //Accessors
    sf::RectangleShape &getShape();
    //Functions
    void updateInput();
    void updateWindowBoundsCollision(sf::RenderTarget *target);
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
};

#endif // PLAYER_HPP
 