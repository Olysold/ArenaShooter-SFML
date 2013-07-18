#include "Player.hpp"

#include <cmath>
#include "util.hpp"

ResourceManager Player::m_resMan;

Player::Player()
{
    m_resMan.texture("Player");
    m_resMan.addAnimation("PlayerAni", "Player");
    m_resMan.addAniFrame("PlayerAni", sf::IntRect(0, 0, 47, 52));
    sprite.setAnimation(m_resMan.getAnimation("PlayerAni"));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f,
                     sprite.getGlobalBounds().height / 2.f);
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
        for(auto& iter : frame)
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
        m_moveHori = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(m_speed * deltaTime.asSeconds(), 0);
        m_moveHori = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -1 * m_speed * deltaTime.asSeconds());
        m_moveVerti = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, m_speed * deltaTime.asSeconds());
        m_moveVerti = true;
    }

    //Rotating player
    //Diagonal movement
    if(m_moveHori && m_moveVerti)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
           !(sprite.getRotation() > 43 && sprite.getRotation() < 47))
        {
            if(sprite.getRotation() < 47 ||
               (sprite.getRotation() < 360 && sprite.getRotation() > 225))
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() > 43 && sprite.getRotation() < 225)
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
           !(sprite.getRotation() > 133 && sprite.getRotation() < 137))
        {
            if(sprite.getRotation() < 137 ||
               (sprite.getRotation() < 360 && sprite.getRotation() > 315))
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() > 133 && sprite.getRotation() < 315)
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
           !(sprite.getRotation() > 313 && sprite.getRotation() < 317))
        {
            if(sprite.getRotation() < 317 && sprite.getRotation() > 135)
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() > 313 ||
                    (sprite.getRotation() < 360 && sprite.getRotation() < 135))
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
           !(sprite.getRotation() > 223 && sprite.getRotation() < 227))
        {
            if(sprite.getRotation() < 227 && sprite.getRotation() > 45)
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() > 223 ||
                    (sprite.getRotation() < 360 && sprite.getRotation() < 45))
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
    }
    //Horizontal and vertical
    else if(m_moveHori)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
           !(sprite.getRotation() > 88 && sprite.getRotation() < 92))
        {
            if(sprite.getRotation() < 88 ||
               (sprite.getRotation() < 360 && sprite.getRotation() > 225))
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() > 92 && sprite.getRotation() < 225)
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
                !(sprite.getRotation() > 268 && sprite.getRotation() < 272))
        {
            if(sprite.getRotation() > 90 && sprite.getRotation() < 272)
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else if(sprite.getRotation() < 90 ||
                    (sprite.getRotation() < 360 && sprite.getRotation() > 268))
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
    }
    else if(m_moveVerti)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
           !(sprite.getRotation() > 0 && sprite.getRotation() < 2))
        {
            if(sprite.getRotation() > 180)
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
           !(sprite.getRotation() > 178 && sprite.getRotation() < 182))
        {
            if(sprite.getRotation() < 180)
            {
                sprite.rotate(m_speed * deltaTime.asSeconds());
            }
            else
            {
                sprite.rotate(-1 * m_speed * deltaTime.asSeconds());
            }
        }
    }

    m_moveHori = false;
    m_moveVerti = false;
}

void Player::shoot(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager& bullets)
{
    m_timeROF += deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if(m_timeROF.asSeconds() >= m_bulletROF)
        {
            sf::Vector2f mousePos(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            mousePos.x = sprite.getPosition().x - mousePos.x;
            mousePos.y = sprite.getPosition().y - mousePos.y;

            //atan2 returns the angle in radians from a vector, in this case the vector(or line) between mousePos and the center of Player
            float rotation = util::radToDeg(std::atan2(-1 * mousePos.x, mousePos.y));

            bullets.createBullet(sprite.getPosition(), rotation, m_bulletSpeed, m_bulletDamage, true);
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
    if (m_health >= damage)
    {
        m_health -= damage;
    }
    else
    {
        m_health = 0;
    }
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
