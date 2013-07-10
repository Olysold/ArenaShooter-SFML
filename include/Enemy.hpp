#ifndef ENEMY_HPP
#define ENEMY_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "Bullet.hpp"

class Enemy
{
public:
    Enemy(unsigned int level); ///Create ResourceManager, set texture? Or leave that to EnemyManager?
    virtual ~Enemy();

    void collision(Player&); ///Interaction Class calls collision functions
    void collision(Bullet&);

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
