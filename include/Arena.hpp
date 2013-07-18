#ifndef ARENA_HPP
#define ARENA_HPP

//3RD
#include <SFML/Graphics.hpp>

//STD

//SELF
#include "ResourceManager.hpp"
#include "Player.hpp"

class Arena
{
public:
    Arena();

    void draw(sf::RenderWindow& window);

    void confinePlayer(Player& player);

    sf::Vector2u getSize();

private:
    sf::Vector2u m_gridSize;
    sf::VertexArray m_grid;

    static ResourceManager m_resMan;
};

#endif
