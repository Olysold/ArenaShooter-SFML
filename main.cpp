//3RD
#include <SFML/Graphics.hpp>

//STD
#include <iostream>

//SELF

/**
Should we look at using vector positions for speed & direction, or would you prefer not to?
Take a look at ECS: ControlSystem and "Utility/Vector.cpp"
If not, bullet/player/enemy needs a float angle, sf::Sprite.setRotation()

P.S are you sure you want to call it Interaction class? CollisionManager sounds appropriate IMO

For bullet collision, we can either do:
1) BulletManager to create and store all bullets, use bool to determine who spawned it.

{
    m_bullets = m_bulMan.getBullets();
    if (m_bullets[i].playerSpawned == true && m_bullets[i].box.intersects(m_enemies[j])
        ...
    else if (m_bullets[i].box.intersects(m_player)
        ...
}

or

2) store bullets in Player/Enemy class, let Interaction class handle who spawned it.

{
    m_enemies = m_enemyMan.getEnemies();
    if (m_enemies[i].bullets[j].box.intersects(m_player))
        ...
    if (m_player.bullets[k].box.intersects(m_enemies[i]))
        ...
}

Now, about multi-line parameters, EnemyManager looks like this:

void createEnemy(unsigned int level,
                 unsigned int health,
                 unsigned int armor,
                 unsigned int shield,
                 unsigned int speed,
                 int damage,
                 unsigned int ROF,
                 unsigned int bulletSpeed,
                 unsigned int bulletDamage);

would you prefer that, or

void createEnemy(unsigned int level,
                 unsigned int health,
                 unsigned int armor,
                 unsigned int shield,
                 unsigned int speed,
                 int damage,
                 unsigned int ROF,
                 unsigned int bulletSpeed,
                 unsigned int bulletDamage
                 );

or

void createEnemy
                (
                    unsigned int level,
                    unsigned int health,
                    unsigned int armor,
                    unsigned int shield,
                    unsigned int speed,
                    int damage,
                    unsigned int ROF,
                    unsigned int bulletSpeed,
                    unsigned int bulletDamage
                );

or

void createEnemy
    (
        unsigned int level,
        unsigned int health,
        unsigned int armor,
        unsigned int shield,
        unsigned int speed,
        int damage,
        unsigned int ROF,
        unsigned int bulletSpeed,
        unsigned int bulletDamage
    );

    also ROF is an acronym, should it still adhere to the camelCase rule and be "rof"?
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Template");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(40, 40, 40));
        window.display();
    }

    return 0;
}
