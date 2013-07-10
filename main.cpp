//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF

///Should we look at using vector positions for speed & direction, or would you prefer not to?

///For bullet collision, we can do:
///1) BulletManager to create and store all bullets, use bool to determine who spawned it.
///     if (m_bullets[i].playerSpawned == true && m_bullets[i].box.intersects(m_enemies[j])
///     else if (m_bullets[i].box.intersects(m_player)

///2) store bullets in Player/Enemy class, let Interaction class handle who spawned it.
///     if (m_enemies[i].bullets[j].box.intersects(m_player))
///     if (m_player.bullets[i].box.intersects(m_enemies[j]))

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Template");

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
