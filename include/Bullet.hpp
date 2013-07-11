#ifndef BULLET_HPP
#define BULLET_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "Enemy.hpp"

class Bullet
{
public:
    Bullet(bool playerBullet, unsigned int speed, int damage); ///Set who shot the bullet
    void update(sf::Time& deltaTime); ///Call to move bullet
    void draw(sf::RenderWindow& window); ///Call to draw bullet

    //TODO
    int getDamage()
    {
        return m_damage;
    }
    sf::Sprite sprite;

private:
    bool            m_playerBullet;

    unsigned int    m_speed;
    int             m_damage;
};

#endif
