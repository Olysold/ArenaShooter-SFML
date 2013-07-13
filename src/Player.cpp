#include "Player.hpp"

Player::Player(): m_resMan(std::make_shared<ResourceManager>()) { }

void Player::createPlayer()
{
    //Set stats
    m_alive = true;
    m_health = 100;
    m_speed = 10; //I'm guessing this is the number of units to move?

    m_bulletSpeed = 0.05; //Seconds
    m_bulletDamage = 20;
    m_bulletROF = 0.1; //Seconds

    m_resMan->texture("Player");
    m_resMan->addAnimation("PlayerAni", "Player");
    m_resMan->addAniFrame("PlayerAni", sf::IntRect(0, 0, 50, 50));
    sprite.setAnimation(m_resMan->getAnimation("PlayerAni"));
}

void Player::move(sf::Time& deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-100 * deltaTime.asSeconds(), 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(100 * deltaTime.asSeconds(), 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -100 * deltaTime.asSeconds());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, 100 * deltaTime.asSeconds());
    }
}

bool Player::isAlive()
{
    return (m_health > 0);
}

void Player::takeDamage(int damage)
{
    m_health -= damage;
}

int Player::getHealth()
{
    return m_health;
}

void Player::draw(sf::RenderWindow& window)
{
    if(m_alive)
    {
        window.draw(sprite);
    }
}
