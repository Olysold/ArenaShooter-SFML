#ifndef BULLETMANAGER_HPP_INCLUDED
#define BULLETMANAGER_HPP_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "Enemy.hpp"

#include <map>
#include <vector>
#include <string>
#include <memory>

class BulletManager
{
public:
    void createPlayerB(Player& player); ///Create bullets at player's location
    void createEnemyB(std::shared_ptr<Enemy> enemy); ///Create bullets at chosen enemy type location

    void cleanup(); ///Call to cleanup bullets that extend out of the arena

private:
    ///Existing bullets
    ///Polymorphic access to various enemies, vector of textured bullets
    std::map<std::shared_ptr<Enemy>,
             std::vector<Bullet>>       m_enemyBullets;
    std::vector<Bullet>                 m_playerBullets;

    const shared_ptr<ResourceManager>   m_resources;
};

#endif // BULLETMANAGER_HPP_INCLUDED
