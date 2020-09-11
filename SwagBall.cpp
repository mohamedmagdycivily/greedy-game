#include "SwagBall.hpp"

void SwagBall::initVariables()
{
    
}

void SwagBall::initShape(sf::RenderTarget *target)
{
    shape.setRadius(rand()%10+10.f);
    sf::Color color;
    switch(type)
    {
        case DEFAULT:
            color = sf::Color(rand() % 255 + 1 , rand() % 255 + 1 , rand() % 255 + 1);
            break;
        case DAMAGING:
            color = sf::Color::Red;
            shape.setOutlineThickness(3);
            shape.setOutlineColor(sf::Color::White);
            break;
        case HEALING:
            color = sf::Color::Green;
            shape.setOutlineThickness(3);
            shape.setOutlineColor(sf::Color::White);
            break;
    }
    shape.setFillColor(color);
    shape.setPosition(rand() % (int)(target->getSize().x - shape.getGlobalBounds().width), rand() % (int)(target->getSize().y - shape.getGlobalBounds().height));
}

SwagBall::SwagBall(sf::RenderTarget *target, int type)
:type{type}{
    initVariables();
    initShape(target);
}

SwagBall::~SwagBall()
{
}

    //Accessors 
sf::CircleShape &SwagBall::getShape()
{
    return shape;
}

int &SwagBall::gettype()
{
    return type;
}
    //Functions
void SwagBall::update()
{
    
}

void SwagBall::render(sf::RenderTarget *target)
{
    target->draw(shape);
}


