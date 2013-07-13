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
    void update(sf::RenderWindow&); ///Call for camera to move to player

private:
    sf::View m_view;

    static Game m_game;
};

#endif
