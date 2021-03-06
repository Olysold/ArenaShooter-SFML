#ifndef ARENA_HPP
#define ARENA_HPP

//3RD
#include <SFML/Graphics.hpp>

//STD

//SELF
#include "Managers/ResourceManager.hpp"
#include "Player.hpp"
#include "Managers/EnemyManager.hpp"

class Arena
{
public:
    Arena();

    void update(EnemyManager& enemyMan);
    void draw(sf::RenderWindow& window);

    void confinePlayer(Player& player);

    sf::Vector2u getSize() const;

private:
    void spawnWave(EnemyManager&);

    unsigned int m_wave;

    sf::Vector2u m_gridSize;
    sf::VertexArray m_grid;

    static ResourceManager m_resMan;
};

#endif
