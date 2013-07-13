#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STD
#include <memory>
#include <list>

//SELF
#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include "BulletManager.hpp"
#include "ResourceManager.hpp"

class BulletManager;

class Player
{
public:
    Player();
    void setStats(const int health,
                  const unsigned int speed,
                  const unsigned int bulletSpd,
                  const int bulletDmg,
                  const unsigned int bulletROF);

    void setTexAni(const std::string texture,
                   const std::string animation,
                   const std::list<sf::IntRect> frames);

    void move(sf::Time&);
    void shoot(sf::Time& deltaTime, BulletManager&);

    void takeDamage(int damage);
    int getHealth();
    bool isAlive();
    void kill();

    sf::Sprite testSprite;
    AnimatedSprite sprite;

    void draw(sf::RenderWindow&);

private:
    bool            m_alive;

    int             m_health;
    unsigned int    m_speed;

    unsigned int    m_bulletSpeed;
    int             m_bulletDamage;
    unsigned int    m_bulletROF;

    const std::shared_ptr<ResourceManager> m_resMan;
};

#endif
