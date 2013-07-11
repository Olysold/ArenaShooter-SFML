#ifndef ENEMY_HPP
#define ENEMY_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STD
#include <memory>

//SELF
#include "AnimatedSprite.hpp"
#include "BulletManager.hpp"

class BulletManager;

class Enemy
{
public:
    Enemy(unsigned int level); ///Create ResourceManager, set texture? Or leave that to EnemyManager?
    virtual ~Enemy();

    void update(sf::Time& deltaTime);
    void draw(sf::RenderWindow&);

    //TODO
    void takeDamage(int damage)
    {
        m_health -= damage;
    }
    int getDamage();

    //TODO
    int getValue()
    {
        return 10;
    }

    AnimatedSprite sprite;
    sf::Sound deathSound;
    sf::Sound shootSound;

private:
    void move(sf::Time& deltaTime);
    void shoot(sf::Time& deltaTime);
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

    const std::shared_ptr<BulletManager> m_bulMan;
};

#endif
