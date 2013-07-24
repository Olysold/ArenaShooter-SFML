#include "Enemy.hpp"

sf::Sound Enemy::m_deathSound;
sf::Sound Enemy::m_shootSound;
BulletManager Enemy::m_bulMan;

Enemy::Enemy(const unsigned int level):
m_level(level)
{
    m_value = 10;
    m_health = (m_level * 50) + 100;
    m_speed = m_level + 1;
    m_damage = m_health / 2.f;
    m_ROF = 1.f - (m_level / 100.f);
    m_bulletSpeed = (m_level * 50) + 200;
    m_bulletDamage = m_damage / 2.f;
}

Enemy::Enemy(const unsigned int level,
             const unsigned int value,
             const unsigned int health,
             const unsigned int speed,
             const unsigned int damage,
             const unsigned int ROF,
             const unsigned int bulletSpeed,
             const unsigned int bulletDamage):
m_level(level),
m_value(value),
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
    animator.playAnimation("Default");
    animator.update(deltaTime);
}

void Enemy::draw(sf::RenderWindow& window)
{
    animator.animate(sprite);
    window.draw(sprite);
}

int Enemy::getDamage() const
{
    return m_damage;
}

int Enemy::getValue() const
{
    return m_value;
}

bool Enemy::isAlive() const
{
    return (m_health > 0);
}

void Enemy::takeDamage(unsigned int damage)
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

