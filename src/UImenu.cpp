#include "UImenu.hpp"

ResourceManager UImenu::m_resMan;

UImenu::UImenu()
{
    m_resMan.font("CenturyGothic");

    ///Main menu
    sf::Text arenaT("ARENA", m_resMan.font("CenturyGothic"));
    arenaT.setCharacterSize(72);
    arenaT.setStyle(sf::Text::Bold);
    arenaT.setPosition(290, 100);
    m_title.push_back(arenaT);

    sf::Text shooterT("SHOOTER", m_resMan.font("CenturyGothic"));
    shooterT.setCharacterSize(72);
    shooterT.setStyle(sf::Text::Bold);
    shooterT.setPosition(255, 170);
    m_title.push_back(shooterT);

    sf::Text startT("Start", m_resMan.font("CenturyGothic"));
    startT.setCharacterSize(25);
    startT.setPosition(360, 360);
    m_selection.push_back(startT);

    sf::Text exitT("Exit", m_resMan.font("CenturyGothic"));
    exitT.setCharacterSize(25);
    exitT.setPosition(360, 410);
    m_selection.push_back(exitT);
}

std::vector<sf::Text> UImenu::getSelection() const
{
    return m_selection;
}

void UImenu::draw(sf::RenderWindow& window)
{
    for(auto srch : m_title)
    {
        window.draw(srch);
    }
    for(auto srch : m_selection)
    {
        window.draw(srch);
    }
}
