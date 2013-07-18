#include "EnemyManager.hpp"

std::vector<Enemy> EnemyManager::m_enemies;
ResourceManager EnemyManager::m_resMan;

EnemyManager::EnemyManager()
{
}

void EnemyManager::createEnemy(sf::Vector2f pos,
                               float rotation,
                               unsigned int level,
                               unsigned int health,
                               unsigned int speed,
                               int damage,
                               unsigned int ROF,
                               unsigned int bulletSpeed,
                               unsigned int bulletDamage)
{
    Enemy ene(level, health, speed, damage, ROF, bulletSpeed, bulletDamage);

    m_resMan.texture("Enemy1");
    m_resMan.addAnimation("Enemy1Ani", "Enemy1");
    m_resMan.addAniFrame("Enemy1Ani", sf::Rect<int>(0, 0, 30, 36));

    ene.sprite.setAnimation(m_resMan.getAnimation("Enemy1Ani"));

    ene.sprite.setOrigin(ene.sprite.getGlobalBounds().width / 2.f,
                     ene.sprite.getGlobalBounds().height / 2.f);
    ene.sprite.setPosition(pos);
    ene.sprite.setRotation(rotation);

    m_enemies.push_back(ene);
}

void EnemyManager::kill(size_t i)
{
    m_enemies.erase(m_enemies.begin() + i);
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return m_enemies;
}
