#include "Game.hpp"

#include <iostream>

#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "CollisionManager.hpp"
#include "Camera.hpp"
//#include "Arena.hpp"

class Enemy;
class Player;
class Bullet;

Game::Game(sf::VideoMode vm, std::string title):
m_score(0)
{
    m_window.create(vm, title);
}

void Game::run()
{
    EnemyManager enemyMan;
    BulletManager bulMan;
    CollisionManager colMan;
    //Arena arena;

    m_window.setFramerateLimit(120);

    sf::Clock currFrame;
    sf::Time deltaTime;
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        for (auto enemy : enemyMan.getEnemies())
        {
            enemy.update(deltaTime);
        }

        for (auto bullet : bulMan.getEnemyBullets())
        {
            bullet.update(deltaTime);
        }

        for (auto bullet : bulMan.getPlayerBullets())
        {
            bullet.update(deltaTime);
        }

        colMan.update(deltaTime);

        m_window.clear(sf::Color(40, 40, 40));

        for (auto& enemy : enemyMan.getEnemies())
        {
            enemy.draw(m_window);
        }

        for (auto& bullet : bulMan.getEnemyBullets())
        {
            bullet.draw(m_window);
        }

        for (auto& bullet : bulMan.getPlayerBullets())
        {
            bullet.draw(m_window);
        }

        m_window.display();

        std::cout << "FPS:" << 1.f / deltaTime.asSeconds() << "\n";
        deltaTime = currFrame.restart();
    }

}
