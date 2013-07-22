#include "Bullet.hpp"

#include <cmath>
#include "util.hpp"

Bullet::Bullet(sf::Vector2f pos,
               float rotation,
               unsigned int speed,
               unsigned int damage,
               sf::Texture& tex):
m_speed(speed),
m_damage(damage)
{
    sprite.setTexture(tex);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
    sprite.setPosition(pos);
    sprite.setRotation(rotation);
}

void Bullet::update(sf::Time& deltaTime)
{
    //These guys will have values between 0 and 1, determining the amount to move on each axis based on rotation.
    float sinMove = std::sin(util::degToRad(sprite.getRotation()));
    float cosMove = std::cos(util::degToRad(sprite.getRotation()));

    //Not sure why rotation is between -180 and 180 instead of 0 and 360 like usual.
    if (sprite.getRotation() <= 0) //Facing south
    {
        sprite.move(m_speed * -1 * sinMove * deltaTime.asSeconds(), m_speed * cosMove * deltaTime.asSeconds());
    }
    else if (sprite.getRotation() > 0) //Facing north
    {
        sprite.move(m_speed * sinMove * deltaTime.asSeconds(), m_speed * -1 * cosMove * deltaTime.asSeconds());
    }
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Bullet::getDamage()
{
    return m_damage;
}
