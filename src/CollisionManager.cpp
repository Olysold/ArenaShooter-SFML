#include "CollisionManager.hpp"

BulletManager CollisionManager::m_bulMan;
EnemyManager  CollisionManager::m_enemyMan;
Game          CollisionManager::m_game;

CollisionManager::CollisionManager()
{
}

void CollisionManager::update(sf::Time& deltaTime, Player& player)
{
    std::vector<Enemy>& enemies = m_enemyMan.getEnemies();
    std::vector<Bullet>& pBullets = m_bulMan.getPlayerBullets();
    std::vector<Bullet>& eBullets = m_bulMan.getEnemyBullets();

    //Enemy hits player
    for (size_t i = 0; i < enemies.size(); ++i)
    {
        auto pRect = player.sprite.getGlobalBounds();
        pRect.width /= 1.25f;
        pRect.height /= 1.25f;
        if (enemies[i].sprite.getGlobalBounds().intersects(pRect))
        {
            std::cout << "Took damage!\n";
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
        //Makes the bounding box smaller, good depending on size/transparency of bullet
        auto bulRect = eBullets[i].sprite.getGlobalBounds();
        bulRect.width /= 4.f;
        bulRect.height /= 4.f;

        auto pRect = player.sprite.getGlobalBounds();
        pRect.width /= 1.25f;
        pRect.height /= 1.25;

        if (bulRect.intersects(pRect))
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
            //Makes the bounding box smaller, good depending on size/transparency of bullet
            auto bulRect = pBullets[i].sprite.getGlobalBounds();
            bulRect.width /= 4.f;
            bulRect.height /= 4.f;

            if (bulRect.intersects(enemies[j].sprite.getGlobalBounds()))
            {
                enemies[j].takeDamage(pBullets[i].getDamage());
                m_bulMan.killPlayerBullet(i);

                if (!enemies[j].isAlive())
                {
                    m_enemyMan.kill(j);
                }
            }
        }
    }
}
