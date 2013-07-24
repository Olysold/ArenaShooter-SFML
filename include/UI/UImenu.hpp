#ifndef UIMENU_HPP_INCLUDED
#define UIMENU_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "Managers/ResourceManager.hpp"

class UImenu
{
public:
    UImenu();
    std::vector<sf::Text> getSelection() const;
    void draw(sf::RenderWindow&);

private:
    std::vector<sf::Text>  m_title;
    std::vector<sf::Text>  m_selection;
    static ResourceManager m_resMan;
};

#endif // UIMENU_HPP_INCLUDED
