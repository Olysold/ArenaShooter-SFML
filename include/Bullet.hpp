#ifndef BULLET_HPP
#define BULLET_HPP

//3RD
#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(bool playerBullet, unsigned int health, unsigned int speed, int damage); ///Set who shot the bullet
    void update(sf::Time deltaTime); ///Call to move bullet
    void draw(sf::RenderWindow& window); ///Call to draw bullet

    void collision(Player&); ///Interaction Class calls collision functions
    void collision(Enemy&);

private:
    bool            playerBullet

    unsigned int    m_speed;
    int             m_damage;
};

#endif
