#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "Game.hpp"

class CollisionManager
{
public:
    CollisionManager();
    void update(sf::Time& deltaTime); ///Call to check for collisions

private:
    const std::shared_ptr<BulletManager> m_bulMan;
    const std::shared_ptr<EnemyManager>  m_enemyMan;
    const std::shared_ptr<Game>          m_game;
    Player                               m_player;
};

#endif
