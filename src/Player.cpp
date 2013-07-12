#include "Player.hpp"

Player::Player()
{
}

void Player::takeDamage(int damage)
{
    m_health -= damage;
}
