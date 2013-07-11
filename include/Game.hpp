#ifndef GAME_HPP
#define GAME_HPP

//3RD
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();

private:
    unsigned int     m_score;

    sf::Time         m_deltaTime;
    sf::RenderWindow m_window;
};

#endif
