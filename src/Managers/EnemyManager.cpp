#include "Managers/EnemyManager.hpp"

std::vector<Enemy> EnemyManager::m_enemies;
ResourceManager EnemyManager::m_resMan;

EnemyManager::EnemyManager(): m_totalScore(0)
{
}

void EnemyManager::createEnemy(sf::Vector2f pos,
                               unsigned int level)
{
    Enemy ene(level);

    ene.sprite.setTexture(m_resMan.texture("Enemy1"));

    auto& edAni = m_resMan.frameAnimation("Enemy Default");
    m_resMan.addFrame("Enemy Default",
                      sf::seconds(1.f),
                      sf::IntRect(0,
                                  0,
                                  m_resMan.texture("Enemy1").getSize().x,
                                  m_resMan.texture("Enemy1").getSize().y));

    ene.animator.addAnimation("Default", edAni, sf::seconds(1.f));
    //m_resMan.addAnimation("Enemy1Ani", "Enemy1");
    //m_resMan.addAniFrame("Enemy1Ani", sf::Rect<int>(0, 0, 30, 36));
    //ene.sprite.setAnimation(m_resMan.getAnimation("Enemy1Ani"));

    ene.sprite.setOrigin(ene.sprite.getGlobalBounds().width / 2.f,
                     ene.sprite.getGlobalBounds().height / 2.f);
    ene.sprite.setPosition(pos);

    m_enemies.push_back(ene);
}

void EnemyManager::createEnemy(sf::Vector2f pos,
                               unsigned int level,
                               unsigned int health,
                               unsigned int speed,
                               unsigned int damage,
                               unsigned int ROF,
                               unsigned int bulletSpeed,
                               unsigned int bulletDamage)
{
    Enemy ene(level, 10, health, speed, damage, ROF, bulletSpeed, bulletDamage);

    m_resMan.texture("Enemy1");
    auto& edAni = m_resMan.frameAnimation("Enemy Default");
    m_resMan.addFrame("Enemy Default",
                      sf::seconds(1.f),
                      sf::IntRect(0,
                                  0,
                                  m_resMan.texture("Enemy1").getSize().x,
                                  m_resMan.texture("Enemy1").getSize().y));

    ene.animator.addAnimation("Default", edAni, sf::seconds(1.f));
    //m_resMan.addAnimation("Enemy1Ani", "Enemy1");
    //m_resMan.addAniFrame("Enemy1Ani", sf::Rect<int>(0, 0, 30, 36));
    //ene.sprite.setAnimation(m_resMan.getAnimation("Enemy1Ani"));

    ene.sprite.setOrigin(ene.sprite.getGlobalBounds().width / 2.f,
                     ene.sprite.getGlobalBounds().height / 2.f);
    ene.sprite.setPosition(pos);

    m_enemies.push_back(ene);
}

void EnemyManager::kill(size_t i)
{
    m_totalScore += m_enemies[i].getValue();

    std::cout << m_totalScore << "\n";

    if(m_enemies.begin() + i == m_enemies.end())
    {
        std::cout << "END ITERATOR\n";
    }
    else
    {
        m_enemies.erase(m_enemies.begin() + i);
    }

}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return m_enemies;
}

unsigned int EnemyManager::getTotalScore() const
{
    return m_totalScore;
}

size_t EnemyManager::numEnemies()
{
    return m_enemies.size();
}
