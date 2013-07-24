#ifndef UIROUNDTITLES_HPP_INCLUDED
#define UIROUNDTITLES_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Managers/ResourceManager.hpp"

class UIroundTitles
{
public:
    UIroundTitles();
    void setTitleDisplay(bool);
    void update(const sf::Time& deltaTime);
    void draw(sf::RenderWindow&) const;

private:
    bool        m_display;
    sf::Time    m_currRoundT;
    sf::Time    m_roundDelayT;
    unsigned    m_roundNum;
    float       m_opacity;
    std::string m_roundStr;
    sf::Text    m_roundTxt;

    static ResourceManager m_resMan;
};

#endif // UIROUNDTITLES_HPP_INCLUDED
