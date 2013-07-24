#include "UIroundTitles.hpp"
#include "util.hpp"

ResourceManager UIroundTitles::m_resMan;

UIroundTitles::UIroundTitles(): m_display(true),
                                m_roundDelayT(sf::seconds(2.5)),
                                m_roundNum(1),
                                m_opacity(0)
{
    m_roundTxt.setFont(m_resMan.font("CenturyGothic"));
    m_roundTxt.setCharacterSize(100);
    m_roundTxt.setPosition(300, 300);
    m_roundTxt.setStyle(sf::Text::Bold);
}

void UIroundTitles::setTitleDisplay(bool toDisplay)
{
    m_display = toDisplay;
}

void UIroundTitles::update(const sf::Time& deltaTime)
{
    if(m_display)
    {
        m_currRoundT += deltaTime;

        m_roundStr = "Round " + util::PODToString(m_roundNum);
        m_roundTxt.setString(m_roundStr);

        if(m_opacity < 255)
        {
            m_opacity = (m_currRoundT.asSeconds() * 300);
        }

        m_roundTxt.setColor(sf::Color(100, 100, 100, m_opacity));

        if(m_currRoundT >= m_roundDelayT)
        {
            m_currRoundT = sf::Time::Zero;
            m_opacity = 0;
            m_roundNum++;
            m_display = false;
        }
    }
}

void UIroundTitles::draw(sf::RenderWindow& window) const
{
    if(m_display)
    {
        window.draw(m_roundTxt);
    }
}
