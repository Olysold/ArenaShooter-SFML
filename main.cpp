//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF
#include "util.hpp"
#include "ResourceManager.hpp"

ResourceManager ResMan;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Template");

    ResMan.texture("Player");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(100, 255, 100));
        window.display();
    }

    return 0;
}
