#ifndef ENEMY_HPP
#define ENEMY_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "AnimatedSprite.hpp"
#include "BulletManager.hpp"

#include <memory>

class Enemy
{
public:
    Enemy(unsigned int level); ///Create ResourceManager, set texture? Or leave that to EnemyManager?
    virtual ~Enemy();

    void update(sf::Time deltaTime);

    AnimatedSprite sprite;
    sf::Sound deathSound;
    sf::Sound shootSound;

private:
    void move(sf::Time deltaTime);
    void shoot(sf::Time deltaTime);
    void dropLoot();

    unsigned int    m_level; ///Used as a factor to multiply stats?

    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;
    int             m_damage; ///Collision damage
    unsigned int    m_ROF;

    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;

    const shared_ptr<BulletManager> m_bullets;
};

#endif
