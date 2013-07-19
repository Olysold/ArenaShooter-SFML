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
#include "AnimatedSprite.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "ResourceManager.hpp"

class Enemy;
class Player;
class Bullet;

class BulletManager
{
public:
    BulletManager();
    void createBullet(sf::Vector2f pos, float rotation, float speed, unsigned int damage, bool playerBullet = false);

    void killEnemyBullet(size_t i);
    void killEnemyBullet(std::vector<Bullet>::iterator);
    void killPlayerBullet(size_t i);
    void killPlayerBullet(std::vector<Bullet>::iterator);

    std::vector<Bullet>& getEnemyBullets();
    std::vector<Bullet>& getPlayerBullets();

    void cleanup(sf::Vector2u arenaSize); ///Call to cleanup bullets that extend out of the arena

private:
    static std::vector<Bullet>  m_enemyBullets;
    static std::vector<Bullet>  m_playerBullets;

    static ResourceManager      m_resMan;
};

//Todo : 1) Textures have not been found/made yet.

#endif
