//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>
#include <list>
#include <cmath>

//SELF
#include "Game.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "CollisionManager.hpp"
#include "util.hpp"

void drawFPS(sf::Time& deltaTime, sf::RenderWindow& window);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bullet Arena");
    window.setVerticalSyncEnabled(true);

    //Controls
    Game game;

    ///TEST
    Player player;
    player.setStats(100, 250, 500, 20, 0.05);
    std::list<sf::IntRect> frame{ sf::IntRect(0, 0, 47, 52) };
    player.setTexAni("Player", "PlayerAni", frame);
    ///TEST

    Camera cam;
    EnemyManager enemyMan;
    BulletManager bulMan;
    CollisionManager colMan;

    //Very Quick Hack, just want to get a reference point while moving.
    enemyMan.createEnemy(10, 10, 10, 10, 10, 10, 10);

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

        ///TEST
        player.move(deltaTime);
        player.shoot(deltaTime, window, bulMan);
        player.sprite.update(deltaTime);
        ///TEST

        cam.update(deltaTime, window, player);
        game.updateEntity(deltaTime, enemyMan, bulMan, colMan);

        window.clear(sf::Color(40, 40, 40));
        game.drawEntity(player, enemyMan, bulMan, window);
        drawFPS(deltaTime, window);
        window.display();
        deltaTime = currFrame.restart();

        //std::cout << "eBul: " << bulMan.getEnemyBullets().size() << "\n";
        //std::cout << "pBul: " << bulMan.getPlayerBullets().size() << "\n";
        //std::cout << "FPS: " << 1.f / deltaTime.asSeconds() << "\n";
    }

    return 0;
}

void drawFPS(sf::Time& deltaTime, sf::RenderWindow& window)
{
    static ResourceManager ResMan;
    int modFPS = std::floor(1.f / (deltaTime.asSeconds() * 5.f)) * 5.f; //Round down to the nearest multiple of 5
    sf::Text FPS(util::PODToString(modFPS),
                 ResMan.font("arial"));

    FPS.setColor(sf::Color(255, 180, 0));
    FPS.setPosition((window.getView().getCenter().x + (window.getView().getSize().x / 2.f)) - (FPS.getGlobalBounds().width * 1.5),
                    (window.getView().getCenter().y - (window.getView().getSize().y / 2.f)) + (FPS.getGlobalBounds().height / 2.f));

    window.draw(FPS);
}
