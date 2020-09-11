#include "Player.hpp"

void Player::initVariables()
{
    movementSpeed = 5.f;
}

void Player::initShape(float x, float y)
{
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(50.f, 60.f));
    shape.setPosition(x, y);
}

void initFonts()
{
    
}

void initText()
{
    
}


Player::Player(float x, float y)
{
    initVariables();
    initShape(x, y);
}

Player::~Player()
{
}

//Accessors
sf::RectangleShape &Player::getShape()
{
    return shape;
}

//Functions
void Player::updateInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        shape.move(-movementSpeed, 0);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        shape.move(movementSpeed, 0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        shape.move(0, movementSpeed);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        shape.move(0, -movementSpeed);
}

void Player::updateWindowBoundsCollision(sf::RenderTarget *target)
{
    if(shape.getGlobalBounds().left <= 0)
        shape.setPosition(0.f, shape.getGlobalBounds().top);
    else if(shape.getGlobalBounds().left >= (float)target->getSize().x - shape.getSize().x)
        shape.setPosition((float)target->getSize().x - shape.getSize().x, shape.getGlobalBounds().top);
    
    if(shape.getGlobalBounds().top <= 0)
        shape.setPosition(shape.getGlobalBounds().left, 0.f);
    else if(shape.getGlobalBounds().top >= (float)target->getSize().y - shape.getSize().y)
        shape.setPosition(shape.getGlobalBounds().left, (float)target->getSize().y - shape.getSize().y);;
}

void Player::update(sf::RenderTarget *target)
{
    updateInput();
    updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(shape);
}