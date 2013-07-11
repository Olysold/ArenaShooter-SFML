#include "Enemy.hpp"

Enemy::Enemy(unsigned int level):
m_level(level)
{
}

Enemy::~Enemy()
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

