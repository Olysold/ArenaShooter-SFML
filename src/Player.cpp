#include "Player.hpp"

#include <cmath>
#include "util.hpp"
#include "Movement.hpp"

ResourceManager Player::m_resMan;

Player::Player(): m_alive(true),
                  m_aniMove(false),
                  m_health(10000),
                  m_speed(250),
                  m_bulletSpeed(500),
                  m_bulletDamage(200),
                  m_bulletROF(0.2)
{
    sprite.setTexture(m_resMan.texture("PSpriteSheet"));
    sprite.setTextureRect(sf::IntRect(0, 0, 47, 60));

    auto& pdAni = m_resMan.frameAnimation("Player Default");
    m_resMan.addFrame("Player Default",
                      sf::seconds(1.f),
                      sf::IntRect(0, 0, 47, 60));

    auto& pmAni = m_resMan.frameAnimation("Player Moving");
    m_resMan.addFrame("Player Moving",
                      sf::seconds(1.f),
                      sf::IntRect(49, 0, 47, 60));
    m_resMan.addFrame("Player Moving",
                      sf::seconds(1.f),
                      sf::IntRect(98, 0, 47, 61));

    animator.addAnimation("Default", pdAni, sf::seconds(1.f));
    animator.addAnimation("Moving", pmAni, sf::seconds(1.f));

    //m_resMan.addAnimation("PlayerAni", "Player");
    //m_resMan.addAniFrame("PlayerAni", sf::IntRect(0, 0, 47, 52));
    //sprite.setAnimation(m_resMan.getAnimation("PlayerAni"));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f,
                     sprite.getGlobalBounds().height / 2.f);
}

void Player::setStats(int health,
                      int speed,
                      unsigned int bulletSpeed,
                      unsigned int bulletDamage,
                      double bulletROF)
{
    m_alive = true;
    m_health = health;
    m_speed = speed;

    m_bulletSpeed = bulletSpeed;
    m_bulletDamage = bulletDamage;
    m_bulletROF = bulletROF; //Seconds
}

void Player::update(sf::Time& deltaTime, sf::RenderWindow& window, BulletManager& bulMan)
{
    this->move(deltaTime);
    this->shoot(deltaTime, window, bulMan);
    if(!animator.isPlayingAnimation())
    {
        animator.playAnimation("Default");
    }
    if(m_aniMove)
    {
        animator.playAnimation("Moving");
    }

    animator.update(deltaTime);
    animator.animate(sprite);
}

void Player::draw(sf::RenderWindow& window)
{
    if (m_alive)
    {
        animator.animate(sprite);
        window.draw(sprite);
    }
}

void Player::move(sf::Time& deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Movement::moveLeft(sprite, m_speed, deltaTime);
        m_moveHori = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Movement::moveRight(sprite, m_speed, deltaTime);
        m_moveHori = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Movement::moveUp(sprite, m_speed, deltaTime);
        m_moveVerti = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Movement::moveDown(sprite, m_speed, deltaTime);
        m_moveVerti = true;
    }

    //Rotating diagonally
    if(m_moveHori && m_moveVerti)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Movement::rotateUpRight(sprite, m_speed, deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Movement::rotateDownRight(sprite, m_speed, deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Movement::rotateUpLeft(sprite, m_speed, deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Movement::rotateDownLeft(sprite, m_speed, deltaTime);
        }
    }
    else if(m_moveHori)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Movement::rotateRight(sprite, m_speed, deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Movement::rotateLeft(sprite, m_speed, deltaTime);
        }
    }
    else if(m_moveVerti)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Movement::rotateUp(sprite, m_speed, deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Movement::rotateDown(sprite, m_speed, deltaTime);
        }
    }

    m_moveHori = false;
    m_moveVerti = false;

    if(!animator.isPlayingAnimation() &&
       (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::D)) )
    {
        m_aniMove = true;
    }
    else
    {
        m_aniMove = false;
    }
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

void Player::takeDamage(unsigned int damage)
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
