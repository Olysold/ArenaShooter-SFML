#include "Player.hpp"

#include <cmath>

ResourceManager Player::m_resMan;

Player::Player()
{
}

void Player::setStats(const int health,
                  const unsigned int speed,
                  const unsigned int bulletSpd,
                  const int bulletDmg,
                  const double bulletROF)
{
    m_alive = true;
    m_health = health;
    m_speed = speed; //I'm guessing this is the number of units to move?

    m_bulletSpeed = bulletSpd;
    m_bulletDamage = bulletDmg;
    m_bulletROF = bulletROF; //Seconds
}

void Player::setTexAni(const std::string texture,
                       const std::string animation,
                       const std::list<sf::IntRect> frame)
{
    m_resMan.texture(texture);
    m_resMan.addAnimation(animation, texture);

    if(!frame.empty())
    {
        for(auto iter : frame)
        {
            m_resMan.addAniFrame(animation, iter);
        }
    }
    else
    {
        std::cerr << "Frames were not set\n";
        m_resMan.addAniFrame(animation, sf::IntRect(0, 0, 0, 0));
    }

    sprite.setAnimation(m_resMan.getAnimation(animation));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Player::move(sf::Time& deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-1 * m_speed * deltaTime.asSeconds(), 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(m_speed * deltaTime.asSeconds(), 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -1 * m_speed * deltaTime.asSeconds());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, m_speed * deltaTime.asSeconds());
    }
}

void Player::shoot(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager& bullets)
{
    m_timeROF += deltaTime;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(m_timeROF.asSeconds() >= m_bulletROF)
        {
            sf::Vector2f mousePos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            mousePos.x = sprite.getPosition().x - mousePos.x;
            mousePos.y = sprite.getPosition().y - mousePos.y;
            float rotation = (std::atan2(-1 * mousePos.x, mousePos.y) * 180.f) / 3.141592653;

            std::cout << mousePos.x << "/" << mousePos.y << "/" << rotation << "\n";
            bullets.createBullet(sprite.getPosition(), rotation, m_bulletSpeed, m_bulletDamage);
            m_timeROF = sf::Time::Zero;
        }
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
