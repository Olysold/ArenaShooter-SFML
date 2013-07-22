#include "Managers/BulletManager.hpp"

std::vector<Bullet> BulletManager::m_enemyBullets;
std::vector<Bullet> BulletManager::m_playerBullets;
ResourceManager BulletManager::m_resMan;

BulletManager::BulletManager()
{
}

void BulletManager::createBullet(sf::Vector2f pos, float rotation, float speed, unsigned int damage, bool playerBullet)
{
    Bullet b(pos, rotation, speed, damage, m_resMan.texture(std::string("Bullet")));

    if (playerBullet)
    {
        m_playerBullets.push_back(b);
    }
    else
    {
        m_enemyBullets.push_back(b);
    }
}

std::vector<Bullet>& BulletManager::getEnemyBullets()
{
    return m_enemyBullets;
}

std::vector<Bullet>& BulletManager::getPlayerBullets()
{
    return m_playerBullets;
}

void BulletManager::killEnemyBullet(size_t i)
{
    m_enemyBullets.erase(m_enemyBullets.begin() + i);
}

void BulletManager::killEnemyBullet(std::vector<Bullet>::iterator iter)
{
    m_enemyBullets.erase(iter);
}

void BulletManager::killPlayerBullet(size_t i)
{
    m_playerBullets.erase(m_playerBullets.begin() + i);
}

void BulletManager::killPlayerBullet(std::vector<Bullet>::iterator iter)
{
    m_playerBullets.erase(iter);
}

void BulletManager::cleanup(sf::Vector2u arenaSize)
{
    if(!m_playerBullets.empty())
    {
        //Temporary out of bounds positions set
        if(m_playerBullets.begin()->sprite.getPosition().x >= arenaSize.x ||
           m_playerBullets.begin()->sprite.getPosition().x <= 0 ||
           m_playerBullets.begin()->sprite.getPosition().y >= arenaSize.y ||
           m_playerBullets.begin()->sprite.getPosition().y <= 0)
        {
            m_playerBullets.erase(m_playerBullets.begin());
        }
    }
}
