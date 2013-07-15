#include "EnemyManager.hpp"

std::vector<Enemy> EnemyManager::m_enemies;
ResourceManager EnemyManager::m_resMan;

EnemyManager::EnemyManager()
{
}

void EnemyManager::kill(size_t i)
{
    m_enemies.erase(m_enemies.begin() + i);
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return m_enemies;
}
