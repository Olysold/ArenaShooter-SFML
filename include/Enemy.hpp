#ifndef ENEMY_HPP
#define ENEMY_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Thor/Animation.hpp>

//STD
#include <memory>

//SELF
#include "Managers/BulletManager.hpp"
#include "Player.hpp"

class BulletManager;
class Player;

class Enemy
{
public:
    Enemy(unsigned int level);

    Enemy(unsigned int level,
          unsigned int m_value,
          unsigned int health,
          unsigned int speed,
          unsigned int damage,
          unsigned int ROF,
          unsigned int bulletSpeed,
          unsigned int bulletDamage);

    void update(const Player&, sf::Time& deltaTime);
    void draw(sf::RenderWindow&);

    int getDamage() const;
    int getValue() const;

    bool isAlive() const;

    void takeDamage(unsigned int damage);

    sf::Sprite sprite;
    thor::Animator<sf::Sprite, std::string> animator;

private:
    void move(const Player&, sf::Time& deltaTime);
    void testMove(const Player&, sf::Time& deltaTime);
    void shoot(const Player&, sf::Time& deltaTime);
    void dropLoot();

    unsigned int    m_level; ///Used as a factor to multiply stats?
                             //Based on experimentation, needs a cap.
    unsigned int    m_value; ///Score value

    bool            m_moving;
    sf::Vector2f    m_targetLoc;

    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;
    unsigned int    m_damage; ///Collision damage
    unsigned int    m_ROF;

    unsigned int    m_bulletSpeed;
    unsigned int    m_bulletDamage;

    static sf::Sound m_deathSound;
    static sf::Sound m_shootSound;
    static BulletManager m_bulMan;
};

#endif
