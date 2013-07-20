#ifndef MOVEMENT_HPP_INCLUDED
#define MOVEMENT_HPP_INCLUDED

//3rd
#include <SFML/Graphics.hpp>

//Self
#include "AnimatedSprite.hpp"

namespace Movement
{
    void moveLeft(AnimatedSprite&, const int&, const sf::Time&);
    void moveRight(AnimatedSprite&, const int&, const sf::Time&);
    void moveUp(AnimatedSprite&, const int&, const sf::Time&);
    void moveDown(AnimatedSprite&, const int&, const sf::Time&);

    //To determine clockwise vs counter-clockwise, consider how the sprite should rotate
    //from the opposite end back to the destination
    void rotateRight(AnimatedSprite&, const int&, const sf::Time&);
    void rotateLeft(AnimatedSprite&, const int&, const sf::Time&);
    void rotateUp(AnimatedSprite&, const int&, const sf::Time&);
    void rotateDown(AnimatedSprite&, const int&, const sf::Time&);
    void rotateUpRight(AnimatedSprite&, const int&, const sf::Time&);
    void rotateDownRight(AnimatedSprite&, const int&, const sf::Time&);
    void rotateUpLeft(AnimatedSprite&, const int&, const sf::Time&);
    void rotateDownLeft(AnimatedSprite&, const int&, const sf::Time&);

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
