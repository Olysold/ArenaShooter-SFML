#include "Camera.hpp"

sf::View Camera::m_view;

Camera::Camera()
{
    m_view.setSize(800, 600);
    m_view.setCenter(0, 0);
}

void Camera::update(sf::Time& deltaTime, sf::RenderWindow& window, Player& player)
{
    m_view.move((player.sprite.getPosition().x - m_view.getCenter().x) * deltaTime.asSeconds() * 3,
                (player.sprite.getPosition().y - m_view.getCenter().y) * deltaTime.asSeconds() * 3);

    window.setView(m_view);
}
