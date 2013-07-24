#ifndef UIPLAYER_H_INCLUDED
#define UIPLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Managers/ResourceManager.hpp"
#include "Player.hpp"

class UIplayer
{
public:
    UIplayer();

    void setDisplayHP(const int);
    void setDisplayShield(const int);
    void setPos(const Player&);
    void updatePos(const sf::Time&, const Player&);
    void draw(sf::RenderWindow&) const;

private:
    sf::RectangleShape m_healthBar;
    sf::RectangleShape m_shieldBar;
};

#endif // UIPLAYER_H_INCLUDED
