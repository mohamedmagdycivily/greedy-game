#include "Game.hpp"

void Game::initVariables()
{
    maxSwagBalls = 20;
    spawnTimerMax = 10;
    spawnTimer = spawnTimerMax;
    
    points = 0;
    maxHealth = 5;
    health = maxHealth;
    
    endGame = false;
}

void Game::initWindow()
{
    videoMode = sf::VideoMode(800.f, 600.f);
    window = new sf::RenderWindow(videoMode, "Game2", sf::Style::Titlebar|sf::Style::Close);
    window->setFramerateLimit(60);
}

void Game::initFonts()
{
    if(!font.loadFromFile("/home/mohamed/Desktop/MY_CODE/Game_Project/Files/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Fonts/Dosis-Light.ttf"))
        std::cout << "Error: cant load from file" <<std::endl;
}

void Game::initText()
{
    text.setFont(font);
    text.setCharacterSize(32);
    text.setColor(sf::Color::White);
    text.setString("Test: ");
}

Game::Game()
{
    initVariables();
    initWindow();
    initFonts();
    initText();
}

Game::~Game()
{
    delete window;
}

//Functions
bool Game::running()
{
    return (window->isOpen() /*&& !endGame*/);
}

void Game::pollEvents()
{
        while(window->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
//                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        window->close();
                    break;
                default:
                    break;
            }
        }
}

void Game::spawnSwagBalls()
{
    if(swagBalls.size() < maxSwagBalls)
    {
        if(spawnTimer >= spawnTimerMax)
        {
            swagBalls.push_back(SwagBall (window, randBallType()));
            spawnTimer = 0;
        }
        else
            spawnTimer++;
    }
}

int Game::randBallType()const
{
    int type = DEFAULT;
    
    int randValue = rand() % 100 + 1;
    if(randValue >= 60 && randValue <= 80)
        type = SwagBallTypes::DAMAGING;
    if(randValue > 80 && randValue <= 100)
        type = SwagBallTypes::HEALING;
        
    return  type;
}

void Game::updateCollision()
{
    for(int i{}; i<swagBalls.size(); i++)
    {
        if(player.getShape().getGlobalBounds().intersects(swagBalls[i].getShape().getGlobalBounds())){
            switch(swagBalls[i].gettype())
            {
                case DAMAGING:
                    if(health > 0)
                        health--;
                    if(health == 0)
                        endGame = true;
                    break;
                case HEALING:
                    if(health < maxHealth)
                        health++;
                    break;
                case DEFAULT:
                    points++;
                    break;
            }
            swagBalls.erase(swagBalls.begin() + i);
        }
    }
}

void Game::updateText()
{
    std::stringstream ss;
    
    if(!endGame)
    {
        ss << "Points: " << points << "\n"
           << "Health: " << health << " / " << maxHealth;
        
    }
    else
    {
        ss << "GAME OVER !" << "\n" 
           << "YOUR SCORE IS : " << points;
        text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().top/2);
        text.setPosition(window->getSize().x/2, window->getSize().y/2);
    }
    
    text.setString(ss.str());
}

void Game::update()
{
    pollEvents();
    if(!endGame)
    {
        player.update(window);
        spawnSwagBalls();
        updateCollision();
    }
    updateText();
}

void Game::renderText(sf::RenderTarget *target)
{
    target->draw(text);
}


void Game::render()
{
    if(!endGame)
    {
        window->clear(sf::Color::Black);
        
        player.render(window);
        
        for(auto &i : swagBalls)
        {
            i.render(window);
        }
        
        renderText(window);
    }
    else
    {
        window->clear(sf::Color::Black);
        renderText(window);
    }
    window->display();
}

