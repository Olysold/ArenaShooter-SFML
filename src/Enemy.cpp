#include "Enemy.hpp"
#include "Movement.hpp"
#include "util.hpp"
#include <cmath>

sf::Sound Enemy::m_deathSound;
sf::Sound Enemy::m_shootSound;
BulletManager Enemy::m_bulMan;

Enemy::Enemy(unsigned int level):
m_level(level)
{
    m_value = 10;
    m_health = (m_level * 50) + 100;
    m_speed = m_level + 100;
    m_damage = m_health / 2.f;
    m_ROF = 1.f - (m_level / 100.f);
    m_bulletSpeed = (m_level * 50) + 200;
    m_bulletDamage = m_damage / 2.f;
}

Enemy::Enemy(unsigned int level,
             unsigned int value,
             unsigned int health,
             unsigned int speed,
             unsigned int damage,
             unsigned int ROF,
             unsigned int bulletSpeed,
             unsigned int bulletDamage):
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

void Enemy::update(const Player& player, sf::Time& deltaTime)
{
    animator.playAnimation("Default");
    animator.update(deltaTime);
    animator.animate(sprite);
    this->move(player, deltaTime);
}

void Enemy::draw(sf::RenderWindow& window)
{
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

void Enemy::move(const Player& player, sf::Time& deltaTime)
{
    sf::Vector2f playerPos = player.sprite.getPosition();
    sf::Vector2f enemyPos = sprite.getPosition();

    double distanceX = playerPos.x - enemyPos.x;
    double distanceY = playerPos.y - enemyPos.y;

    if(util::isNegative(distanceX))
    {
        Movement::moveLeft(sprite, m_speed, deltaTime);
    }
    if(!util::isNegative(distanceX))
    {
        Movement::moveRight(sprite, m_speed, deltaTime);
    }
    if(util::isNegative(distanceY))
    {
        Movement::moveUp(sprite, m_speed, deltaTime);
    }
    if(!util::isNegative(distanceY))
    {
        Movement::moveDown(sprite, m_speed, deltaTime);
    }

    //Rotating
    float targetAngle = util::radToDeg(std::atan2(-1 * distanceX, distanceY)) + 180;
    float actualAngle = sprite.getRotation();

    //MAGIC ROTATION CODE

    sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
}

void Enemy::shoot(const Player&, sf::Time& deltaTime)
{

}
