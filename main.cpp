//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF
#include "ResourceManager.hpp"

ResourceManager ResMan;

int main()
{
    sf::Sound Test(ResMan.soundBuffer("test"));
    Test.play();

    sf::RenderWindow window(sf::VideoMode(200, 200), "Template");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(40, 40, 40));
        window.display();
    }

    Test.stop();

    return 0;
}
