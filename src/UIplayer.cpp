#include "UIplayer.hpp"

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

void UIplayer::setPos(const int x, const int y)
{
    m_healthBar.setPosition(x, y);
    m_shieldBar.setPosition(x, y + 5);
}

void UIplayer::updatePos(const int x,
                         const int y,
                         const double speed,
                         const sf::Time& deltaTime)
{
    m_healthBar.move(x * speed * deltaTime.asSeconds(),
                     y * speed * deltaTime.asSeconds() );

    m_shieldBar.move(x * speed * deltaTime.asSeconds(),
                     y * speed * deltaTime.asSeconds() );
}

void UIplayer::draw(sf::RenderWindow& window) const
{
    window.draw(m_healthBar);
    window.draw(m_shieldBar);
}
