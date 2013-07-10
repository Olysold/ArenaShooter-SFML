#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    sf::Sprite sprite;

private:
    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;

    unsigned int    m_bulletHealth;
    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;
    unsigned int    m_bulletROF;
};

#endif
