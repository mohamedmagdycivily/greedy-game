#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "SwagBall.hpp"

#include <vector>
#include <iostream>
#include <sstream>

class Game
{
private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    
    sf::Font font;
    sf::Text text;
    
    Player player;
    
    std::vector<SwagBall>swagBalls;
    int maxSwagBalls;
    int spawnTimer;
    int spawnTimerMax;
    
    int health;
    int maxHealth;
    int points;
    
    bool endGame;
    
    //Initialization
    void initVariables();
    void initWindow();
    
    void initFonts();
    void initText();
    
public:
    //constructor & destructor
    Game();
    ~Game();
    
    //Accessors
    
    //Functions
    bool running();
    void pollEvents();
    void spawnSwagBalls();
    int randBallType()const;
    void updateCollision();
    void updateText();
    void update();
    void renderText(sf::RenderTarget *target);
    void render();

};

#endif // GAME_HPP
