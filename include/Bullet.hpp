#ifndef BULLET_HPP
#define BULLET_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Player.hpp"
#include "Enemy.hpp"

#include <map>
#include <vector>
#include <string>
#include <memory>

class Bullet
{
public:
    Bullet(bool playerBullet, unsigned int speed, int damage); ///Set who shot the bullet
    void updateEnemyB(sf::Time deltaTime); ///Call to move enemy bullets
    void updatePlayerB(sf::Time deltaTime); ///Call to move player bullets

    void createPlayerB(Player& player); ///Create bullets at player's location
    void createEnemyB(std::shared_ptr<Enemy> enemy); ///Create bullets at chosen enemy type location

    void cleanup(); ///Call to cleanup bullets that extend out of the arena
    void draw(sf::RenderWindow& window); ///Call to draw bullet

    void collision(Player&); ///Interaction Class calls collision functions
    void collision(Enemy&);

private:
    ///Existing bullets
    ///Polymorphic access to various enemies, vector of textured bullets
    std::map<std::shared_ptr<Enemy>,
             std::vector<sf::Sprite>>       m_enemyBullets;
    std::vector<sf::Sprite>                 m_playerBullets;


    std::vector<sf::Time> m_currTime;
    std::vector<sf::Time> m_speed;

    ///To get varied textured bullets
    const std::shared_ptr<ResourceManager> m_resources;
};

#endif
