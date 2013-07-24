#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <memory>
#include <string>

//SELF
#include "Player.hpp"
#include "Managers/EnemyManager.hpp"
#include "Managers/BulletManager.hpp"
#include "Managers/CollisionManager.hpp"
#include "Camera.hpp"
#include "Arena.hpp"

class CollisionManager;

class Game
{
public:
    Game();

    void updateEntity(sf::Time&, EnemyManager&, BulletManager&, CollisionManager&, Arena&, Player&);
    void drawEntity(Player&, EnemyManager&, BulletManager&, Arena&, sf::RenderWindow&);

    bool isGameOver();
    void gameOver();

private:
    static bool m_gameOver;
    static unsigned int m_score;

    static ResourceManager m_resMan;
};

#endif
