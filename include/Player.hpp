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

class BulletManager;

class Player
{
public:
    Player();

    void update(sf::Time& deltaTime);
    void draw(sf::RenderWindow& window);

    int getHealth();

    void takeDamage(int damage);

    bool isAlive();

    AnimatedSprite sprite;
    sf::Sound deathSound;
    sf::Sound shootSound;

private:
    void move(sf::Time deltaTime);
    void shoot(sf::Time deltaTime);
    void dropLoot();

    int             m_health;
    unsigned int    m_speed;

    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;
    unsigned int    m_bulletROF;

    const std::shared_ptr<BulletManager> m_bulMan;
    const std::shared_ptr<ResourceManager> m_resMan;
};

#endif
