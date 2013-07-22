#include "Enemy.hpp"

sf::Sound Enemy::m_deathSound;
sf::Sound Enemy::m_shootSound;
BulletManager Enemy::m_bulMan;

Enemy::Enemy(unsigned int level):
m_level(level)
{
    m_health = (m_level * 50) + 100;
    m_speed = m_level + 1;
    m_damage = m_health / 2.f;
    m_ROF = 1.f - (m_level / 100.f);
    m_bulletSpeed = (m_level * 50) + 200;
    m_bulletDamage = m_damage / 2.f;
}

Enemy::Enemy(unsigned int level,
             unsigned int health,
             unsigned int speed,
             unsigned int damage,
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
    animator.playAnimation("Default");
    animator.update(deltaTime);
}

void Enemy::draw(sf::RenderWindow& window)
{
    animator.animate(sprite);
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

