#include "Game.hpp"

#include <iostream>

void Game::updateEntity(sf::Time& deltaTime,
                        EnemyManager& enemyMan,
                        BulletManager& bulMan,
                        CollisionManager& colMan)
{
    if(!enemyMan.getEnemies().empty())
    {
        for (auto& enemy : enemyMan.getEnemies())
        {
            enemy.update(deltaTime);
        }
    }

    if(!bulMan.getEnemyBullets().empty())
    {
        for (auto& bullet : bulMan.getEnemyBullets())
        {
            bullet.update(deltaTime);
        }
    }

    if(!bulMan.getPlayerBullets().empty())
    {
        for (auto& bullet : bulMan.getPlayerBullets())
        {
            bullet.update(deltaTime);
        }
    }

    ///colMan.update(deltaTime);
}

void Game::drawEntity(Player& player,
                      EnemyManager& enemyMan,
                      BulletManager& bulMan,
                      sf::RenderWindow& window)
{
    //window.draw(player.getPlayer());

    if(!enemyMan.getEnemies().empty())
    {
        for (auto enemy : enemyMan.getEnemies())
        {
            enemy.draw(window);
        }
    }

    //if(!bulMan.getEnemeyBullets().empty())
    {
        //for (auto bullet : bulMan.getEnemyBullets())
        {
            //bullet.draw(window);
        }
    }

    if(!bulMan.getEnemyBullets().empty())
    {
        for (auto bullet : bulMan.getPlayerBullets())
        {
            bullet.draw(window);
        }
    }
}
