#ifndef ENEMY_HPP
#define ENEMY_HPP

//3RD
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(unsigned int level); ///Create ResourceManager, set texture?
    virtual ~Enemy();

    sf::Sprite sprite;

private:
    unsigned int    m_level; ///Used as a factor to multiply stats?

    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;
    int             m_damage; ///Collision damage
    unsigned int    m_ROF;

    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;
};

#endif
