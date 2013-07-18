#include "Enemy.hpp"

sf::Sound Enemy::m_deathSound;
sf::Sound Enemy::m_shootSound;
BulletManager Enemy::m_bulMan;

Enemy::Enemy(unsigned int level,
             unsigned int health,
             unsigned int speed,
             int damage,
             unsigned int ROF,
             unsigned int bulletSpeed,
             unsigned int bulletDamage):
m_level(level),
m_health(health),
m_speed(speed),
m_damage(damage),
m_ROF(ROF),
m_bulletSpeed(bulletSpeed),
m_bulletDamage(bulletDamage)
{
}

void Enemy::update(sf::Time& deltaTime)
{

}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Enemy::getDamage()
{
    return m_damage;
}

int Enemy::getValue()
{
    return m_value;
}

bool Enemy::isAlive()
{
    return (m_health > 0);
}

void Enemy::takeDamage(int damage)
{
    if (damage <= m_health)
    {
        m_health -= damage;
    }
    else
    {
        m_health = 0;
    }
}

