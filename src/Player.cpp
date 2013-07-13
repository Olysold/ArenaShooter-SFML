#include "Player.hpp"

Player::Player()
{
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Player::getHealth()
{
    return m_health;
}

void Player::takeDamage(int damage)
{
    m_health -= damage;
}

bool Player::isAlive()
{
    return (m_health > 0);
}
