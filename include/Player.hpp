#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Thor/Animation.hpp>

//STD
#include <memory>

//SELF
#include "Managers/BulletManager.hpp"
#include "Managers/ResourceManager.hpp"

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

    void update(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager& bulMan);

    void takeDamage(unsigned int damage);

    int getHealth();
    bool isAlive();

    void kill();

    sf::Sprite sprite;
    thor::Animator<sf::Sprite, std::string> animator;

    void draw(sf::RenderWindow&);

private:
    void move(sf::Time&);
    void shoot(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager&);

    bool            m_alive;
    bool            m_aniMove;

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
