#include "EnemyManager.hpp"

EnemyManager::EnemyManager()
{
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return m_enemies;
}
