#include "EnemyManager.hpp"

std::vector<Enemy> EnemyManager::m_enemies;
ResourceManager EnemyManager::m_resMan;

EnemyManager::EnemyManager()
{
}

void EnemyManager::createEnemy(unsigned int level,
                               unsigned int health,
                               unsigned int speed,
                               int damage,
                               unsigned int ROF,
                               unsigned int bulletSpeed,
                               unsigned int bulletDamage)
{
    //Very Quick Hack, just want to get a reference point while moving.
    Enemy enemy(0, 0);

    m_resMan.texture("Enemy1");
    m_resMan.addAnimation("Enemy1Ani", "Enemy1");
    m_resMan.addAniFrame("Enemy1Ani", sf::Rect<int>(0, 0, 30, 36));

    enemy.sprite.setAnimation(m_resMan.getAnimation("Enemy1Ani"));

    enemy.sprite.setOrigin(enemy.sprite.getGlobalBounds().width / 2.f,
                     enemy.sprite.getGlobalBounds().height / 2.f);

    enemy.sprite.setPosition(0, 0);

    m_enemies.push_back(enemy);
}

void EnemyManager::kill(size_t i)
{
    m_enemies.erase(m_enemies.begin() + i);
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return m_enemies;
}
