#ifndef SWAGBALL_HPP
#define SWAGBALL_HPP

#include "SFML/Graphics.hpp"
#include <ctime>

enum SwagBallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall
{
private:
    sf::CircleShape shape;
    int type;
    
    void initShape(sf::RenderTarget *target);
    void initVariables();
public:
    SwagBall(sf::RenderTarget *target, int);
    ~SwagBall();
    
    //Accessors 
    sf::CircleShape &getShape();
    int &gettype();
    //Functions
    void update();
    void render(sf::RenderTarget *target);

};

#endif // SWAGBALL_HPP
