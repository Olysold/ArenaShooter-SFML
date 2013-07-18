#include "Game.hpp"

#include <iostream>

bool Game::m_gameOver = false;
unsigned int Game::m_score = 0;
ResourceManager Game::m_resMan;

Game::Game()
{
}

void Game::updateEntity(sf::Time& deltaTime,
                        EnemyManager& enemyMan,
                        BulletManager& bulMan,
                        CollisionManager& colMan,
                        Arena& arena,
                        Player& player)
{
    if (!m_gameOver)
    {
        arena.confinePlayer(player);

        for (auto& enemy : enemyMan.getEnemies())
        {
            enemy.update(deltaTime);
        }

        for (auto& bullet : bulMan.getEnemyBullets())
        {
            bullet.update(deltaTime);
        }

        for (auto& bullet : bulMan.getPlayerBullets())
        {
            bullet.update(deltaTime);
        }

        colMan.update(deltaTime, player);
        bulMan.cleanup(arena.getSize()); //Disabled until we have an arena and thus know the boundaries.
    }
}

void Game::drawEntity(Player& player,
                      EnemyManager& enemyMan,
                      BulletManager& bulMan,
                      Arena& arena,
                      sf::RenderWindow& window)
{
    if (!m_gameOver)
    {
        arena.draw(window);

        ///Conclusion: GlobalBounds collision doesn't take in to account rotation (look at dark red player vs enemy), we should use LocalBounds or it will be innacurate

        //Debug what player's global bounds looks like
        sf::RectangleShape debugP;

        debugP.setSize(sf::Vector2f(player.sprite.getGlobalBounds().width, player.sprite.getGlobalBounds().height));
        debugP.setOrigin(debugP.getSize().x / 2.f, debugP.getSize().y / 2.f);
        debugP.setPosition(player.sprite.getPosition());
        debugP.setRotation(player.sprite.getRotation());
        debugP.setFillColor(sf::Color(255, 0, 0));

        window.draw(debugP);

        //Debug player global bounds, without rotation.
        sf::RectangleShape debugPA = debugP;
        debugPA.setRotation(0);
        debugPA.setFillColor(sf::Color(100, 0, 0));

        window.draw(debugPA);

        //Debug what player's local bounds looks like
        sf::RectangleShape debugP2;
        debugP2.setSize(sf::Vector2f(player.sprite.getLocalBounds().width, player.sprite.getLocalBounds().height));
        debugP2.setOrigin(debugP2.getSize().x / 2.f, debugP2.getSize().y / 2.f);
        debugP2.setPosition(player.sprite.getPosition());
        debugP2.setRotation(player.sprite.getRotation());
        debugP2.setFillColor(sf::Color(0, 255, 0));

        window.draw(debugP2);

        for (auto bullet : bulMan.getEnemyBullets())
        {
            bullet.draw(window);
        }

        for (auto bullet : bulMan.getPlayerBullets())
        {
            bullet.draw(window);
        }

        for (auto enemy : enemyMan.getEnemies())
        {
            //Debug what enemies global bounds looks like
            sf::RectangleShape debugP;

            debugP.setSize(sf::Vector2f(enemy.sprite.getGlobalBounds().width, enemy.sprite.getGlobalBounds().height));
            debugP.setOrigin(debugP.getSize().x / 2.f, debugP.getSize().y / 2.f);
            debugP.setPosition(enemy.sprite.getPosition());
            debugP.setRotation(enemy.sprite.getRotation());
            debugP.setFillColor(sf::Color(255, 0, 0));

            window.draw(debugP);

            //Debug enemies global bounds, without rotation.
            sf::RectangleShape debugPA = debugP;
            debugPA.setRotation(0);
            debugPA.setFillColor(sf::Color(100, 0, 0));

            window.draw(debugPA);

            //Debug what enemies local bounds looks like
            sf::RectangleShape debugP2;
            debugP2.setSize(sf::Vector2f(enemy.sprite.getLocalBounds().width, enemy.sprite.getLocalBounds().height));
            debugP2.setOrigin(debugP2.getSize().x / 2.f, debugP2.getSize().y / 2.f);
            debugP2.setPosition(enemy.sprite.getPosition());
            debugP2.setRotation(enemy.sprite.getRotation());
            debugP2.setFillColor(sf::Color(0, 255, 0));

            enemy.draw(window);
        }

        player.draw(window);
    }
}

void Game::addScore(unsigned int score)
{
    m_score += score;
}

bool Game::isGameOver()
{
    return m_gameOver;
}

void Game::gameOver()
{
    m_gameOver = true;
    std::cout << "Game Over!\n";
}
