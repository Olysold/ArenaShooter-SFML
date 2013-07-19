#include "Arena.hpp"

ResourceManager Arena::m_resMan;

Arena::Arena():
m_wave(1),
m_grid(sf::Quads)
{
    unsigned int floorSize = m_resMan.texture("Floor").getSize().x;
    //Unlikely to work if x and y are different, keep that in mind.
    m_gridSize = sf::Vector2u(floorSize * 32, floorSize * 32);
    m_grid.resize((m_gridSize.x / floorSize) * (m_gridSize.y / floorSize) * 4);

    for (size_t i = 0; i < m_gridSize.x / floorSize; ++i)
    {
        for (size_t j = 0; j < m_gridSize.y / floorSize; ++j)
        {
            //Create a quad, easier to work with.
            sf::Vertex* quad = &m_grid[(i + j * (m_gridSize.y/floorSize)) * 4];
            quad[0].position = sf::Vector2f(i*floorSize, j*floorSize);
            quad[1].position = sf::Vector2f(i*floorSize + floorSize, j*floorSize);
            quad[2].position = sf::Vector2f(i*floorSize + floorSize, j*floorSize + floorSize);
            quad[3].position = sf::Vector2f(i*floorSize, j*floorSize + floorSize);

            //Set each vertex to a corner of the texture
            quad[0].texCoords = sf::Vector2f(0, 0);
            quad[1].texCoords = sf::Vector2f(floorSize, 0);
            quad[2].texCoords = sf::Vector2f(floorSize, floorSize);
            quad[3].texCoords = sf::Vector2f(0, floorSize);

            for (int k = 0; k < 4; ++k)
            {
                quad[k].color = sf::Color(255, 255, 255, 255); //Might be unnecessary?
            }
        }
    }
}

void Arena::update(EnemyManager& enemyMan)
{
    if (enemyMan.numEnemies() == 0)
    {
        this->spawnWave(enemyMan);
    }
}

void Arena::draw(sf::RenderWindow& window)
{
    window.draw(m_grid, &m_resMan.texture("Floor"));
}

void Arena::spawnWave(EnemyManager& enemyMan)
{
    unsigned int numEnemies = (m_wave * 10) + 50;
    for (unsigned int i = 0; i < numEnemies; ++i)
    {
        switch (std::rand() % 4)
        {
        case 0:
            enemyMan.createEnemy(sf::Vector2f(std::rand() % m_gridSize.x,
                                              0),
                                 m_wave);
            break;
        case 1:
            enemyMan.createEnemy(sf::Vector2f(std::rand() % m_gridSize.x,
                                              m_gridSize.y),
                                 m_wave);
            break;
        case 2:
            enemyMan.createEnemy(sf::Vector2f(0,
                                              std::rand() % m_gridSize.y),
                                 m_wave);
            break;
        case 3:
            enemyMan.createEnemy(sf::Vector2f(m_gridSize.x,
                                              std::rand() % m_gridSize.y),
                                 m_wave);
            break;
        default:
            std::cout << "WAVE SPAWN ERROR\n";
            enemyMan.createEnemy(sf::Vector2f(0, 0), m_wave);
            break;
        }

    }

    m_wave++;
}

void Arena::confinePlayer(Player& player)
{
    sf::Vector2f pos = player.sprite.getPosition();
    sf::FloatRect texRect = player.sprite.getGlobalBounds();

    if (pos.x - texRect.width / 2.f < 0)
    {
        pos.x = 0 + texRect.width / 2.f;
        player.sprite.setPosition(pos.x, pos.y);
    }

    if (pos.x + texRect.width / 2.f > m_gridSize.x)
    {
        pos.x = m_gridSize.x - texRect.width / 2.f;
        player.sprite.setPosition(pos.x, pos.y);
    }

    if (pos.y - texRect.height / 2.f < 0)
    {
        pos.y = 0 + texRect.height / 2.f;
        player.sprite.setPosition(pos.x, pos.y);
    }

    if (pos.y + texRect.height / 2.f > m_gridSize.y)
    {
        pos.y = m_gridSize.y - texRect.height / 2.f;
        player.sprite.setPosition(pos.x, pos.y);
    }
}

sf::Vector2u Arena::getSize()
{
    return m_gridSize;
}

