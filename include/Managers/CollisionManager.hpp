#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>

#include <vector>

//SELF
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "Game.hpp"

class BulletManager;
class EnemyManager;
class Game;

class CollisionManager
{
public:
    CollisionManager();
    void update(sf::Time& deltaTime, Player& player, EnemyManager& enemyMan, BulletManager& bulMan, Game& game); ///Call to check for collisions

private:
    std::vector<size_t> m_numEnemyCollide;

};

#endif
