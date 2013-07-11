#include "Player.hpp"

Player::Player()
{
}

Player::takeDamage(int damage)
{
    m_health -= damage;
}
