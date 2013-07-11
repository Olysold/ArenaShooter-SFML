#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"

class CollisionManager
{
public:
    CollisionManager();
    void update(sf::RenderWindow&); ///Call to check for collisions

private:
    void collision(Player&, Enemy&);
    void collision(Bullet&, Player&);
    void collision(Bullet&, Enemy&);

    const std::shared_ptr<BulletManager> m_bulMan;
    const std::shared_ptr<EnemyManager>  m_enemyMan;
};

#endif
