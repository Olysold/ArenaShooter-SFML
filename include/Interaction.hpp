#ifndef INTERACTION_HPP
#define INTERACTION_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "EnemyManager.hpp"
#include "Player.hpp"

class Interaction
{
public:
    Interaction();
    void update(sf::RenderWindow&); ///Call to check for collisions

private:
};

#endif
