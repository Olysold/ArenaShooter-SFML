#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "EnemyManager.hpp"
#include "Player.hpp"
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

    BulletManager m_bulMan;
};

#endif
