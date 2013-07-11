#ifndef GAME_HPP
#define GAME_HPP

//3RD
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();

private:
    sf::RenderWindow m_window;
    sf::Time m_deltaTime;

    unsigned int m_score;
};

#endif
