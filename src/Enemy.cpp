#include "Enemy.hpp"

BulletManager Enemy::m_bulMan;

Enemy::Enemy(unsigned int level, unsigned int m_score):
m_level(level)
{
    m_health = 100;
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
    std::cout << m_health << "-" << damage << "\n";

    if (damage <= m_health)
    {
        m_health -= damage;
    }
    else
    {
        m_health = 0;
    }
}

