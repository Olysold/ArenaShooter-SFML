#include "BulletManager.hpp"

ResourceManager BulletManager::m_resMan;

BulletManager::BulletManager()
{
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

void BulletManager::killPlayerBullet(size_t i)
{
    m_playerBullets.erase(m_playerBullets.begin() + i);
}

