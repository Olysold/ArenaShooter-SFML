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
    Enemy(unsigned int level,
          unsigned int health,
          unsigned int speed,
          int damage,
          unsigned int ROF,
          unsigned int bulletSpeed,
          unsigned int bulletDamage);

    void update(sf::Time& deltaTime);
    void draw(sf::RenderWindow&);

    int getDamage();
    int getValue();

    bool isAlive();

    void takeDamage(int damage);

    AnimatedSprite sprite;

private:
    void move(sf::Time& deltaTime);
    void shoot(sf::Time& deltaTime);
    void dropLoot();

    unsigned int    m_level; ///Used as a factor to multiply stats?
    unsigned int    m_value; ///Score value

    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;
    int             m_damage; ///Collision damage
    unsigned int    m_ROF;

    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;

    static sf::Sound m_deathSound;
    static sf::Sound m_shootSound;
    static BulletManager m_bulMan;
};

#endif
