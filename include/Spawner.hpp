#ifndef SPAWNER_H_INCLUDED
#define SPAWNER_H_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <vector>
#include <string>
#include <random>

//Self
#include "Arena.hpp"
#include "Game.hpp"
#include "Managers/EnemyManager.hpp"

class Game;

class Spawner
{
public:
    Spawner(Arena&);
    void update(const sf::Time&, const Game&, EnemyManager&);

private:
    void spawnWaveOne(const sf::Time&, EnemyManager&);

    unsigned m_level;
    sf::Time m_currTime;
    sf::Time m_spawnDelay;
    const sf::Vector2u m_arenaSize;

    std::uniform_real_distribution<double>  m_doorSize;
    std::uniform_int_distribution<unsigned> m_randLoc;
    std::default_random_engine m_engine;
};


#endif // SPAWNER_H_INCLUDED
