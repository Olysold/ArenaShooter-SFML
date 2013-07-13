#include "Bullet.hpp"

Bullet::Bullet(bool playerBullet, unsigned int speed, int damage):
m_playerBullet(playerBullet),
m_speed(speed),
m_damage(damage)
{
}

void Bullet::update(sf::Time& deltaTime)
{

}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Bullet::getDamage()
{
    return m_damage;
}
