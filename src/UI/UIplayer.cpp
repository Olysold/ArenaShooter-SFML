#include "UI/UIplayer.hpp"
#include "Movement.hpp"
#include "util.hpp"

#include <iostream>

UIplayer::UIplayer()
{
    const int width = 50;
    const int height = 3;

    m_healthBar.setSize(sf::Vector2f(width, height));
    m_healthBar.setFillColor(sf::Color::Green);

    m_shieldBar.setSize(sf::Vector2f(width, height));
    m_shieldBar.setFillColor(sf::Color::Blue);
}

void UIplayer::setDisplayHP(const int width)
{
    m_healthBar.setSize(sf::Vector2f(width, 3));
}

void UIplayer::setDisplayShield(const int width)
{
    m_shieldBar.setSize(sf::Vector2f(width, 3));
}

void UIplayer::setPos(const Player& player)
{
    auto bottomPosX = player.sprite.getGlobalBounds().left;
    auto bottomPosY = player.sprite.getGlobalBounds().top +
                      player.sprite.getLocalBounds().height;

    m_healthBar.setPosition(bottomPosX, bottomPosY);
    m_shieldBar.setPosition(bottomPosX, bottomPosY + 5);
}

void UIplayer::updatePos(const sf::Time& deltaTime, const Player& player)
{
    auto playerBottomX = player.sprite.getPosition().x -
                        (player.sprite.getLocalBounds().width / 2);
    auto playerBottomY = player.sprite.getPosition().y +
                        (player.sprite.getLocalBounds().height / 2);

    auto healthX = m_healthBar.getPosition().x;
    auto healthY = m_healthBar.getPosition().y;

    auto shieldX = m_shieldBar.getPosition().x;
    auto shieldY = m_shieldBar.getPosition().y;

    //Follow upwards
    if( (healthX || shieldX) != playerBottomX)
    {
        double distance = playerBottomX - healthX;

        m_healthBar.move(distance, 0);
        m_shieldBar.move(distance, 0);
    }
    //Follow downwards
    if( (healthY || shieldY) != playerBottomY)
    {
        double distance = playerBottomY - healthY;

        m_healthBar.move(0, distance);
        m_shieldBar.move(0, distance);
    }
}

void UIplayer::draw(sf::RenderWindow& window) const
{
    window.draw(m_healthBar);
    window.draw(m_shieldBar);
}
