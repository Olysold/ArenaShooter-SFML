#include "Player.hpp"

Player::Player(): m_resMan(std::make_shared<ResourceManager>()) { }

void Player::setStats(const int health,
                  const unsigned int speed,
                  const unsigned int bulletSpd,
                  const int bulletDmg,
                  const unsigned int bulletROF)
{
    m_alive = true;
    m_health = health;
    m_speed = speed; //I'm guessing this is the number of units to move?

    m_bulletSpeed = bulletSpd; //Seconds
    m_bulletDamage = bulletDmg;
    m_bulletROF = bulletROF; //Seconds
}

void Player::setTexAni(const std::string texture,
                       const std::string animation,
                       const std::list<sf::IntRect> frame)
{
    m_resMan->texture(texture);
    m_resMan->addAnimation(animation, texture);

    if(!frame.empty())
    {
        for(auto iter : frame)
        {
            m_resMan->addAniFrame(animation, iter);
        }
    }
    else
    {
        std::cerr << "Frames were not set\n";
        m_resMan->addAniFrame(animation, sf::IntRect(0, 0, 0, 0));
    }

    sprite.setAnimation(m_resMan->getAnimation(animation));
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

void Player::shoot(sf::Time& deltaTime, BulletManager& bullets)
{

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
