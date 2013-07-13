#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

//STD
#include <vector>

//SELF
#include "Enemy.hpp"

#include <memory>

///Manages creation and storage of all Enemies
class EnemyManager
{
public:
    EnemyManager();

    void createEnemy(unsigned int level,
                     unsigned int health,
                     unsigned int armor,
                     unsigned int shield,
                     unsigned int speed,
                     int damage,
                     unsigned int ROF,
                     unsigned int bulletSpeed,
                     unsigned int bulletDamage);

    void kill(size_t i);
    void kill(std::vector<Enemy>::iterator&);

    std::vector<Enemy>& getEnemies(); ///For collision handling

private:
    std::vector<Enemy> m_enemies;

    static ResourceManager m_resMan;
};

#endif
