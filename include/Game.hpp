#ifndef GAME_HPP
#define GAME_HPP

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <memory>
#include <string>

//SELF

class Game
{
public:
    Game(sf::VideoMode, std::string);
    void run();

private:
    unsigned int     m_score;

    sf::Time         m_deltaTime;
    sf::RenderWindow m_window;
};

#endif
