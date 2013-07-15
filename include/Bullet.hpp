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
    Bullet(sf::Vector2f pos, float rotation, unsigned int speed, int damage); ///Set who shot the bullet
    void update(sf::Time& deltaTime); ///Call to move bullet
    void draw(sf::RenderWindow& window); ///Call to draw bullet

    int getDamage();

    sf::Sprite sprite;

private:
    float   m_speed;
    int     m_damage;
};

#endif
