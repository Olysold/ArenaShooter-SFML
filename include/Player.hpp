#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STD
#include <memory>

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
    void setStats(int health,
                  int speed,
                  unsigned int bulletSpeed,
                  unsigned int bulletDamage,
                  double bulletROF);

    void setTexAni(std::string texture,
                   std::string animation,
                   std::vector<sf::IntRect> frames);


    void update(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager& bulMan);

    void takeDamage(unsigned int damage);

    int getHealth();
    bool isAlive();

    void kill();

    AnimatedSprite sprite;

    void draw(sf::RenderWindow&);

private:
    void move(sf::Time&);
    void shoot(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager&);

    bool            m_alive;

    unsigned int    m_health;
    int             m_speed;

    unsigned int    m_bulletSpeed;
    unsigned int    m_bulletDamage;
    sf::Time        m_timeROF;
    double          m_bulletROF;

    bool            m_moveHori;
    bool            m_moveVerti;

    static ResourceManager m_resMan;
};

#endif
