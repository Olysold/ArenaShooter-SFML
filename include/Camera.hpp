#ifndef CAMERA_HPP
#define CAMERA_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Game.hpp"

class Game;

class Camera
{
public:
    Camera();
    void update(sf::Time&, sf::RenderWindow&, Player&); ///Call for camera to move to player

private:
    static sf::View m_view;
};

#endif
