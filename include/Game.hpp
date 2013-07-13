#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <memory>
#include <string>

//SELF
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "BulletManager.hpp"
#include "CollisionManager.hpp"
#include "Camera.hpp"

class CollisionManager;

class Game
{
public:
    Game();

    void updateEntity(sf::Time&, EnemyManager&, BulletManager&, CollisionManager&);
    void drawEntity(Player&, EnemyManager&, BulletManager&, sf::RenderWindow&);

    Player& getPlayer();

    void addScore(unsigned int);

    void gameOver();

private:
    bool m_gameOver;
    unsigned int m_score;
    Player m_player;

    static ResourceManager m_resMan;
};

#endif
