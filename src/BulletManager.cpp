#include "BulletManager.hpp"

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
