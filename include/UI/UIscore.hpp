#ifndef UISCORE_HPP_INCLUDED
#define UISCORE_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

#include "Managers/ResourceManager.hpp"
#include "Managers/EnemyManager.hpp"
#include "Camera.hpp"

class UIscore
{
public:
    UIscore();
    void setPos(const Camera&);
    void updatePos(const sf::Time&, const Camera&);
    void updateScore(const EnemyManager&);

    void draw(sf::RenderWindow&);

private:
    sf::Text     m_textDisplay;
    std::string  m_strScore;

    static ResourceManager m_resMan;
};


#endif // UISCORE_HPP_INCLUDED
