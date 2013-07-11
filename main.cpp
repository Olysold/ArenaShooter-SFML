//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF
#include "Game.hpp"

int main()
{
    Game game(sf::VideoMode(640, 640), "Bullet Arena");
    game.run();

    return 0;
}
