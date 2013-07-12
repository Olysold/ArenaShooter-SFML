#include "CollisionManager.hpp"

CollisionManager::CollisionManager()
{
}

void CollisionManager::update(sf::Time& deltaTime)
{
    auto enemies = m_enemyMan->getEnemies();
    auto pBullets = m_bulMan->getPlayerBullets();
    auto eBullets = m_bulMan->getEnemyBullets();

    //Enemy hits player
    for (size_t i = 0; i < enemies.size(); ++i)
    {
        if (enemies[i].sprite.getGlobalBounds().intersects(m_player.sprite.getGlobalBounds()))
        {
            m_player.takeDamage(enemies[i].getDamage());
            ///m_game->score += enemies[i].getValue();
            ///m_enemyMan->kill(i);

            if (m_player.getHealth() <= 0)
            {
                ///m_player.kill();
            }
        }
    }

    //Enemy Bullets hit player
    for (size_t i = 0; i < eBullets.size(); ++i)
    {
        if (eBullets[i].sprite.getGlobalBounds().intersects(m_player.sprite.getGlobalBounds()))
        {
            m_player.takeDamage(eBullets[i].getDamage());
            ///m_bulMan->kill(i);

            if (m_player.getHealth() <= 0)
            {
               ///m_player.kill();
            }
        }
    }

    //Player Bullets hit enemy
    for (size_t i = 0; i < pBullets.size(); ++i)
    {
        for (size_t j = 0; j < enemies.size(); ++j)
        {
            if (pBullets[i].sprite.getGlobalBounds().intersects(enemies[i].sprite.getGlobalBounds()))
            {
                ///enemies.takeDamage(pBullets[i].getDamage());
                ///m_bulMan->kill(i);

                ///if (enemies[i].getHealth() <= 0)
                {
                    ///m_enemyMan->kill(i);
                }
            }
        }
    }
}
