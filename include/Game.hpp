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

    static unsigned int     score;

private:
    static sf::Time         m_deltaTime;
    static sf::RenderWindow m_window;
};

#endif
