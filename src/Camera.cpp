#include "Camera.hpp"

sf::View Camera::m_view;

Camera::Camera(Player& player)
{
    m_view.setSize(800, 600);
    m_view.setCenter(player.sprite.getPosition().x, player.sprite.getPosition().y);
}

sf::View Camera::getCamera() const
{
    return m_view;
}

void Camera::update(sf::Time& deltaTime, sf::RenderWindow& window, Player& player, sf::Vector2u arenaSize)
{
    sf::Vector2f playerPos = player.sprite.getPosition();

    m_view.move((playerPos.x - m_view.getCenter().x) * deltaTime.asSeconds() * 3,
                (playerPos.y - m_view.getCenter().y) * deltaTime.asSeconds() * 3);

    if (m_view.getCenter().x < m_view.getSize().x / 2)
    {
        m_view.setCenter(m_view.getSize().x / 2, m_view.getCenter().y);
    }
    else if (m_view.getCenter().x > arenaSize.x - m_view.getSize().x / 2)
    {
        m_view.setCenter(arenaSize.x - m_view.getSize().x / 2, m_view.getCenter().y);
    }

    if (m_view.getCenter().y < m_view.getSize().y / 2)
    {
        m_view.setCenter(m_view.getCenter().x, m_view.getSize().y / 2);
    }
    else if (m_view.getCenter().y > arenaSize.y - m_view.getSize().y / 2)
    {
        m_view.setCenter(m_view.getCenter().x, arenaSize.y - m_view.getSize().y / 2);
    }

    window.setView(m_view);
}
