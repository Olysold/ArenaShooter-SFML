#include "Game.hpp"

#include <iostream>

ResourceManager Game::m_resMan;

Game::Game():
m_gameOver(false),
m_score(0)
{

}

void Game::updateEntity(sf::Time& deltaTime,
                        EnemyManager& enemyMan,
                        BulletManager& bulMan,
                        CollisionManager& colMan)
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

    colMan.update(deltaTime, m_player);
}

void Game::drawEntity(Player& player,
                      EnemyManager& enemyMan,
                      BulletManager& bulMan,
                      sf::RenderWindow& window)
{
    player.draw(window);

    for (auto enemy : enemyMan.getEnemies())
    {
        enemy.draw(window);
    }

    for (auto bullet : bulMan.getEnemyBullets())
    {
        bullet.draw(window);
    }

    for (auto bullet : bulMan.getPlayerBullets())
    {
        bullet.draw(window);
    }
}

Player& Game::getPlayer()
{
    return m_player;
}

void Game::addScore(unsigned int score)
{
    m_score += score;
}

void Game::gameOver()
{
    m_gameOver = true;
}
