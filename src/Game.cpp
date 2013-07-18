#include "Game.hpp"

#include <iostream>

bool Game::m_gameOver = false;
unsigned int Game::m_score = 0;
ResourceManager Game::m_resMan;

Game::Game()
{
}

void Game::updateEntity(sf::Time& deltaTime,
                        EnemyManager& enemyMan,
                        BulletManager& bulMan,
                        CollisionManager& colMan,
                        Player& player)
{
    if (!m_gameOver)
    {
        for (auto& enemy : enemyMan.getEnemies())
        {
            enemy.update(deltaTime);
        }

        for (auto& bullet : bulMan.getEnemyBullets())
        {
            bullet.update(deltaTime);
        }

        for (auto& bullet : bulMan.getPlayerBullets())
        {
            bullet.update(deltaTime);
        }

        colMan.update(deltaTime, player);
        //bulMan.cleanup(); //Disabled until we have an arena and thus know the boundaries.
    }
}

void Game::drawEntity(Player& player,
                      EnemyManager& enemyMan,
                      BulletManager& bulMan,
                      sf::RenderWindow& window)
{
    if (!m_gameOver)
    {
        for (auto bullet : bulMan.getEnemyBullets())
        {
            bullet.draw(window);
        }

        for (auto bullet : bulMan.getPlayerBullets())
        {
            bullet.draw(window);
        }

        for (auto enemy : enemyMan.getEnemies())
        {
            enemy.draw(window);
        }

        player.draw(window);
    }
}

void Game::addScore(unsigned int score)
{
    m_score += score;
}

bool Game::isGameOver()
{
    return m_gameOver;
}

void Game::gameOver()
{
    m_gameOver = true;
    std::cout << "Game Over!\n";
}
