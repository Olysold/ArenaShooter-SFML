#ifndef CAMERA_HPP
#define CAMERA_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Game.hpp"

class Camera
{
public:
    Camera(Player& player);
    sf::View getCamera() const;
    void update(sf::Time&, sf::RenderWindow&, Player&, sf::Vector2u arenaSize); ///Call for camera to move to player

private:
    static sf::View m_view;
};

#endif
