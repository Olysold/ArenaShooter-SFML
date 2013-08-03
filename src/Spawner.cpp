#include "Spawner.hpp"

#include <iostream>

Spawner::Spawner(Arena& arena): m_level(1),
                                m_spawnDelay(sf::seconds(1.0f)),
                                m_arenaSize(arena.getSize()),
                                m_doorSize
                                (
                                    (arena.getSize().x / 2) - (arena.getSize().x / 6),
                                    (arena.getSize().x / 2) + (arena.getSize().x / 6)
                                ),
                                m_randLoc(0, 3)
{
}

void Spawner::update(const sf::Time& deltaTime,
                     const Game& game,
                     EnemyManager& enemyMan)
{
    //if(!game.isRoundEnd()) Placeholder

        spawnWaveOne(deltaTime, enemyMan);


    //else
    {
        //++m_level; Or get the level from game instead.
    }




}

void Spawner::spawnWaveOne(const sf::Time& deltaTime,
                           EnemyManager& enemyMan)
{
    m_currTime += deltaTime;

    if(m_currTime > m_spawnDelay)
    {
        switch(m_randLoc(m_engine))
        {
        case 0:
            enemyMan.createTypeOne(sf::Vector2f(m_doorSize(m_engine), 0),
                                   m_level);
            break;
        case 1:
            enemyMan.createTypeOne(sf::Vector2f(m_arenaSize.x, m_doorSize(m_engine)),
                                   m_level);
            break;
        case 2:
            enemyMan.createTypeOne(sf::Vector2f(m_doorSize(m_engine), m_arenaSize.y),
                                   m_level);
            break;
        case 3:
            enemyMan.createTypeOne(sf::Vector2f(0, m_doorSize(m_engine)),
                                   m_level);
            break;
        default:
            std::cerr << "An error was found in m_randLoc\n";
            break;
        }

        m_currTime = sf::Time::Zero;
    }
}
