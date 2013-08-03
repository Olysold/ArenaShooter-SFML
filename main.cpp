//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdlib>

//SELF
#include "Arena.hpp"
#include "Game.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "Managers/EnemyManager.hpp"
#include "Managers/BulletManager.hpp"
#include "Managers/CollisionManager.hpp"
#include "util.hpp"
#include "Spawner.hpp"
#include "UI/UI.hpp"

void drawFPS(sf::Time& deltaTime, sf::RenderWindow& window);

int main()
{
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bullet Arena");
    window.setVerticalSyncEnabled(true);

    //Controls
    Game game;
    Arena arena;
    EnemyManager enemyMan;
    BulletManager bulMan;
    CollisionManager colMan;

    Player player;
    player.sprite.setPosition(arena.getSize().x / 2.f, arena.getSize().y / 2.f);

    Camera cam(player);
    Spawner spawner(arena);
    UI userInter(player, cam);

    //Time
    sf::Clock currFrame;
    sf::Time deltaTime;

    sf::Event event;

    while(window.isOpen() && game.isGameOver() == false)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(userInter.isMainMenu()) //If it's the main menu
        {
            userInter.mainMenu(window, deltaTime);
        }
        else //Game functionality becomes active
        {
            player.update(deltaTime, window, bulMan);
            cam.update(deltaTime, window, player, arena.getSize());
            userInter.update(deltaTime, player, enemyMan, cam);
            game.updateEntity(deltaTime, enemyMan, bulMan, colMan, arena, player, spawner);
        }

        window.clear(sf::Color(40, 40, 40));

        if(userInter.isMainMenu())
        {
            userInter.drawMenu(window);
        }
        else
        {
            userInter.drawIngame(window);
            game.drawEntity(player, enemyMan, bulMan, arena, window);
            drawFPS(deltaTime, window);
        }

        window.display();

        deltaTime = currFrame.restart();


    }

    std::cout << "eBul: " << bulMan.getEnemyBullets().size() << "\n";
    std::cout << "pBul: " << bulMan.getPlayerBullets().size() << "\n";
    std::cout << "FPS: " << 1.f / deltaTime.asSeconds() << "\n";
    std::cout << "Enemies: " << enemyMan.getEnemies().size() << "\n";

    sf::sleep(sf::seconds(1));
    return 0;
}

void drawFPS(sf::Time& deltaTime, sf::RenderWindow& window)
{
    static ResourceManager ResMan;
    int modFPS = std::floor(1.f / (deltaTime.asSeconds() * 5.f)) * 5.f; //Round down to the nearest multiple of 5
    sf::Text FPS(util::PODToString(modFPS), ResMan.font("arial"));

    FPS.setColor(sf::Color(255, 180, 0));
    FPS.setPosition((window.getView().getCenter().x + (window.getView().getSize().x / 2.f)) - (FPS.getGlobalBounds().width * 1.5),
                    (window.getView().getCenter().y - (window.getView().getSize().y / 2.f)) + (FPS.getGlobalBounds().height / 2.f));

    window.draw(FPS);
}
