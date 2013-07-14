#include "BulletManager.hpp"

BulletManager::BulletManager()
{
}

void BulletManager::createPlayerB(AnimatedSprite& sprite)
{
    auto midPoint = (sprite.getGlobalBounds().top +
                     sprite.getGlobalBounds().width) / 2;

    //Bind values of speed and damage to the bullet itself or
    //take that from data in Player?
    Bullet pBullet(true, 100, 20);
    pBullet.sprite.setPosition(sprite.getPosition().x + midPoint,
                               sprite.getPosition().y);

    m_playerBullets.push_back(pBullet);
}

void BulletManager::createEnemyB(std::shared_ptr<Enemy> enemy)
{
    auto midPoint = (enemy->sprite.getGlobalBounds().top +
                     enemy->sprite.getGlobalBounds().width) / 2;

    //Bind values of speed and damage to the bullet itself or
    //take that from data in Enemy?
    Bullet eBullet(false, 100, 20);
    eBullet.sprite.setPosition(enemy->sprite.getPosition().x + midPoint,
                               enemy->sprite.getPosition().y);

    m_enemyBullets.push_back(eBullet);
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

void BulletManager::cleanup()
{
    if(!m_playerBullets.empty())
    {
        //Temporary out of bounds positions set
        if(m_playerBullets.begin()->sprite.getPosition().x >= 800 ||
           m_playerBullets.begin()->sprite.getPosition().x <= 0 ||
           m_playerBullets.begin()->sprite.getPosition().y >= 600 ||
           m_playerBullets.begin()->sprite.getPosition().y <= 0)
        {
            m_playerBullets.erase(m_playerBullets.begin());
        }
    }

    if(!m_enemyBullets.empty())
    {
        //Temporary out of bounds positions set
        if(m_enemyBullets.begin()->sprite.getPosition().x >= 800 ||
           m_enemyBullets.begin()->sprite.getPosition().x <= 0 ||
           m_enemyBullets.begin()->sprite.getPosition().y >= 600 ||
           m_enemyBullets.begin()->sprite.getPosition().y <= 0)
        {
            m_enemyBullets.erase(m_enemyBullets.begin());
        }
    }

}
