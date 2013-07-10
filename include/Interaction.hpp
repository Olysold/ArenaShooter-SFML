#ifndef INTERACTION_HPP
#define INTERACTION_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "EnemyManager.hpp"
#include "Player.hpp"

///Should each class have a collision function? or manually let Interaction handle it?

///player/enemy/bullet have a collision function for eachother, not sure if good/bad/pointless
///perhaps collision functions should only run code that affects them, which makes sense
///e.g if player collides with enemy (or vice-versa), player collision removes health, enemy collision flags itself as dead and spawns coins
class Interaction
{
public:
    Interaction();
    void update(sf::RenderWindow&); ///Call to check for collisions

private:
};

#endif
