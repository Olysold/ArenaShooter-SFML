#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STD
#include <memory>

//SELF
#include "AnimatedSprite.hpp"
#include "BulletManager.hpp"
#include "ResourceManager.hpp"

class Player
{
public:
    Player();

    void kill();

    void update(sf::Time deltaTime);

    AnimatedSprite sprite;
    sf::Sound deathSound;
    sf::Sound shootSound;

private:
    void move(sf::Time deltaTime);
    void shoot(sf::Time deltaTime);
    void dropLoot();

    bool            m_alive;

    unsigned int    m_health;
    unsigned int    m_armor;
    unsigned int    m_shield;
    unsigned int    m_speed;

    unsigned int    m_bulletHealth;
    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;
    unsigned int    m_bulletROF;

    const std::shared_ptr<BulletManager> m_bullets;
    const std::shared_ptr<ResourceManager> m_resources;
};

#endif
