#include "UI.hpp"

ResourceManager UI::m_resMan;

UI::UI(): m_selectDelay(sf::seconds(0.3)),
          m_numChoices(0),
          m_mainMenu(true),
          m_delay(true),
          m_roundDelayT(sf::seconds(2.5)),
          m_roundNum(1),
          m_opacity(0)
{
    m_resMan.font("CenturyGothic");

    //Ideally I imagine that titles would be textures rather than fonts
    ///Main menu
    sf::Text arenaT("ARENA", m_resMan.font("CenturyGothic"));
    arenaT.setCharacterSize(72);
    arenaT.setStyle(sf::Text::Bold);
    arenaT.setPosition(290, 100);
    m_textMap["Title"].push_back(arenaT);

    sf::Text shooterT("SHOOTER", m_resMan.font("CenturyGothic"));
    shooterT.setCharacterSize(72);
    shooterT.setStyle(sf::Text::Bold);
    shooterT.setPosition(255, 170);
    m_textMap["Title"].push_back(shooterT);

    sf::Text startT("Start", m_resMan.font("CenturyGothic"));
    startT.setCharacterSize(25);
    startT.setPosition(360, 360);
    m_textMap["MainScreenSelect"].push_back(startT);

    sf::Text exitT("Exit", m_resMan.font("CenturyGothic"));
    exitT.setCharacterSize(25);
    exitT.setPosition(360, 410);
    m_textMap["MainScreenSelect"].push_back(exitT);

    ///Selection arrow
    m_selectArrow.setTexture(m_resMan.texture("Selection"));
    m_selectArrow.setPosition(m_textMap["MainScreenSelect"][0].getPosition().x - 15,
                              m_textMap["MainScreenSelect"][0].getPosition().y - 2);

    ///ROUND DELAY
    m_roundTxt.setFont(m_resMan.font("CenturyGothic"));
    m_roundTxt.setCharacterSize(100);
    m_roundTxt.setPosition(300, 300);
    m_roundTxt.setStyle(sf::Text::Bold);
}

void UI::update(sf::Time& deltaTime)
{
    //Round Delay
    if(!m_mainMenu && m_delay)
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
            m_delay = false;
        }
    }
}

bool UI::isMainMenu() const
{
    return m_mainMenu;
}

void UI::mainMenu(const unsigned selection, sf::RenderWindow& window)
{
    if(selection == 0)
    {
        m_mainMenu = false;
    }
    if(selection == 1)
    {
        window.close();
    }
}

unsigned UI::vertiMenuNavigator(const std::string mapKey, sf::Time deltaTime)
{
    m_currMenuT += deltaTime;

    if(m_textMap.find(mapKey) != m_textMap.end())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if((m_keyUp || m_currMenuT > m_selectDelay) &&
            m_selectArrow.getPosition().y != (m_textMap[mapKey].end()-1)->getPosition().y - 2)
            {
                m_selectArrow.move(0, ((m_textMap[mapKey][m_numChoices + 1]).getPosition().y) -
                                       (m_textMap[mapKey][m_numChoices].getPosition().y) );
                m_numChoices++;

                m_keyUp = false;
                m_currMenuT = sf::Time::Zero;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if((m_keyUp || m_currMenuT > m_selectDelay) &&
                m_selectArrow.getPosition().y != m_textMap[mapKey].begin()->getPosition().y - 2)
            {
                m_selectArrow.move(0, ((m_textMap[mapKey][m_numChoices - 1]).getPosition().y) -
                                       (m_textMap[mapKey][m_numChoices].getPosition().y) );
                m_numChoices--;

                m_keyUp = false;
                m_currMenuT = sf::Time::Zero;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            return m_numChoices;
        }
    }
    else
    {
        std::cerr << "No such map key found. Data may not have been inserted." << "\n";
    }

    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
        !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        !m_keyUp)
    {
        m_keyUp = true;
    }
}

void UI::drawMainMenu(sf::RenderWindow& window)
{
    if(m_mainMenu)
    {
        window.draw(m_selectArrow);

        for(auto srch : m_textMap["Title"])
        {
            window.draw(srch);
        }
        for(auto srch : m_textMap["MainScreenSelect"])
        {
            window.draw(srch);
        }
    }
}

void UI::drawRoundDelay(sf::RenderWindow& window)
{
    if(m_delay && !m_mainMenu)
    {
        window.draw(m_roundTxt);
    }
}
