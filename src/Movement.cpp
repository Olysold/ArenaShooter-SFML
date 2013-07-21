#include "Movement.hpp"

void Movement::moveLeft(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    sprite.move(-1 * speed * deltaTime.asSeconds(), 0);
}

void Movement::moveRight(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    sprite.move(speed * deltaTime.asSeconds(), 0);
}

void Movement::moveUp(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    sprite.move(0, -1 * speed * deltaTime.asSeconds());
}

void Movement::moveDown(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    sprite.move(0, speed * deltaTime.asSeconds());
}

void Movement::rotateRight(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (east-2) && sprite.getRotation() < (east+2) ))
    {
        if(sprite.getRotation() < (east-2) ||
          (sprite.getRotation() < north360 && sprite.getRotation() > west))
        {
            //Rotating clockwise
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() > (east+2) && sprite.getRotation() < west)
        {
            //Rotating counter-clockwise
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateLeft(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (west-2) && sprite.getRotation() < (west+2) ))
    {
        if(sprite.getRotation() < (west+2) && sprite.getRotation() > east)
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() < east ||
               (sprite.getRotation() < north360 && sprite.getRotation() > (west-2)))
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateUp(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > north0 && sprite.getRotation() < (north0+2) ))
    {
        if(sprite.getRotation() > south)
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateDown(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (south-2) && sprite.getRotation() < (south+2) ))
    {
        if(sprite.getRotation() > north0)
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() < north360)
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateUpRight(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (northEast-2) && sprite.getRotation() < (northEast+2) ))
    {
        if(sprite.getRotation() < (northEast+2) ||
          (sprite.getRotation() < north360 && sprite.getRotation() > southWest))
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() > (northEast-2) && sprite.getRotation() < southWest)
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateDownRight(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (southEast-2) && sprite.getRotation() < (southEast+2) ))
    {
        if(sprite.getRotation() < (southEast+2) ||
          (sprite.getRotation() < north360 && sprite.getRotation() > northWest ))
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() > (southEast-2) && sprite.getRotation() < northWest)
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateUpLeft(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (northWest-2) && sprite.getRotation() < (northWest+2) ))
    {
        if(sprite.getRotation() < (northWest+2) && sprite.getRotation() > southEast)
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() > (northWest-2) ||
               (sprite.getRotation() < north360 && sprite.getRotation() < southEast))
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}

void Movement::rotateDownLeft(sf::Sprite& sprite, const int& speed, const sf::Time& deltaTime)
{
    if(!(sprite.getRotation() > (southWest-2) && sprite.getRotation() < (southWest+2) ))
    {
        if(sprite.getRotation() < (southWest+2) && sprite.getRotation() > northEast)
        {
            sprite.rotate(speed * deltaTime.asSeconds());
        }
        else if(sprite.getRotation() > (southWest-2) ||
               (sprite.getRotation() < north360 && sprite.getRotation() < northEast))
        {
            sprite.rotate(-1 * speed * deltaTime.asSeconds());
        }
    }
}
