//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF
#include "Game.hpp"
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "CollisionManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bullet Arena");
    window.setFramerateLimit(120);

    //Controls
    Game game;

    Player player;
    EnemyManager enemyMan;
    BulletManager bulMan;
    CollisionManager colMan;

    //Time
    sf::Clock currFrame;
    sf::Time deltaTime;

    sf::Event event;
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.updateEntity(deltaTime, enemyMan, bulMan, colMan);

        window.clear(sf::Color(40, 40, 40));
        game.drawEntity(player, enemyMan, bulMan, window);
        window.display();

        std::cout << "FPS:" << 1.f / currFrame.getElapsedTime().asSeconds() << "\n";
        deltaTime = currFrame.restart();
    }



    return 0;
}
