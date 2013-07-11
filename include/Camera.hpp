#ifndef CAMERA_HPP
#define CAMERA_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"

class Camera
{
public:
    Camera(Player&); ///Camera stores a reference to the player to get player's location
    void update(sf::RenderWindow&); ///Call for camera to move to player

private:
    Player& m_player;
};

#endif
