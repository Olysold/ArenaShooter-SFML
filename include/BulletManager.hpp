#ifndef BULLETMANAGER_HPP_INCLUDED
#define BULLETMANAGER_HPP_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <vector>
#include <string>
#include <memory>

//SELF
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "ResourceManager.hpp"

class Enemy;
class Player;
class Buller;

class BulletManager
{
public:
    BulletManager();
    void createPlayerB(Player& player); ///Create bullets at player's location
    void createEnemyB(std::shared_ptr<Enemy> enemy); ///Create bullets at chosen enemy type location

    void cleanup(); ///Call to cleanup bullets that extend out of the arena

private:
    std::vector<Bullet>                     m_enemyBullets;
    std::vector<Bullet>                     m_playerBullets;

    const std::shared_ptr<ResourceManager>  m_resMan;
};

#endif
