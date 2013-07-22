#ifndef MOVEMENT_HPP_INCLUDED
#define MOVEMENT_HPP_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//SELF

namespace Movement
{
    void moveLeft(sf::Sprite&, const int&, const sf::Time&);
    void moveRight(sf::Sprite&, const int&, const sf::Time&);
    void moveUp(sf::Sprite&, const int&, const sf::Time&);
    void moveDown(sf::Sprite&, const int&, const sf::Time&);

    //To determine clockwise vs counter-clockwise, consider how the sprite should rotate
    //from the opposite end back to the destination
    void rotateRight(sf::Sprite&, const int&, const sf::Time&);
    void rotateLeft(sf::Sprite&, const int&, const sf::Time&);
    void rotateUp(sf::Sprite&, const int&, const sf::Time&);
    void rotateDown(sf::Sprite&, const int&, const sf::Time&);
    void rotateUpRight(sf::Sprite&, const int&, const sf::Time&);
    void rotateDownRight(sf::Sprite&, const int&, const sf::Time&);
    void rotateUpLeft(sf::Sprite&, const int&, const sf::Time&);
    void rotateDownLeft(sf::Sprite&, const int&, const sf::Time&);

    const int north0 = 0;
    const int north360 = 360;
    const int south = 180;
    const int east = 90;
    const int west = 270;
    const int northEast = 45;
    const int southEast = 135;
    const int northWest = 315;
    const int southWest = 225;
}

#endif // MOVEMENT_H_INCLUDED
