#include "CollisionManager.hpp"

BulletManager CollisionManager::m_bulMan;
EnemyManager  CollisionManager::m_enemyMan;
Game          CollisionManager::m_game;

CollisionManager::CollisionManager()
{
}

void CollisionManager::update(sf::Time& deltaTime, Player& player)
{
    auto enemies = m_enemyMan.getEnemies();
    auto pBullets = m_bulMan.getPlayerBullets();
    auto eBullets = m_bulMan.getEnemyBullets();

    //Enemy hits player
    /*for (size_t i = 0; i < enemies.size(); ++i)
    {
        if (enemies[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
        {
            player.takeDamage(enemies[i].getDamage());
            m_game.addScore(enemies[i].getValue());
            m_enemyMan.kill(i);

            if (!player.isAlive())
            {
                m_game.gameOver();
            }
        }
    }

    //Enemy Bullets hit player
    for (size_t i = 0; i < eBullets.size(); ++i)
    {
        if (eBullets[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
        {
            player.takeDamage(eBullets[i].getDamage());
            m_bulMan.killEnemyBullet(i);

            if (!player.isAlive())
            {
               m_game.gameOver();
            }
        }
    }

    //Player Bullets hit enemy
    for (size_t i = 0; i < pBullets.size(); ++i)
    {
        for (size_t j = 0; j < enemies.size(); ++j)
        {
            if (pBullets[i].sprite.getGlobalBounds().intersects(enemies[j].sprite.getGlobalBounds()))
            {
                enemies[j].takeDamage(pBullets[i].getDamage());
                m_bulMan.killPlayerBullet(i);

                if (!enemies[j].isAlive())
                {
                    m_enemyMan.kill(i);
                }
            }
        }
    }*/
}
