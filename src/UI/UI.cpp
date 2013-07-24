#include "UI/UI.hpp"
using std::string;
using std::vector;

ResourceManager UI::m_resMan;

UI::UI(const Player& player, const Camera& cam): m_selectDelay(sf::seconds(0.3)),
                                                 m_mainMenu(true),
                                                 m_numChoices(0)
{
    ///Selection arrow
    m_selectArrow.setTexture(m_resMan.texture("Selection"));
    m_selectArrow.setPosition(m_menuInter.getSelection()[0].getPosition().x - 15,
                              m_menuInter.getSelection()[0].getPosition().y - 2);

    m_playerInter.setPos(player);
    m_scoreInter.setPos(cam);
}

void UI::update(const sf::Time& deltaTime,
                const Player& player,
                const EnemyManager& eneMan,
                const Camera& cam)
{
    m_roundInter.update(deltaTime);
    m_playerInter.updatePos(deltaTime, player);
    m_scoreInter.updateScore(eneMan);
    m_scoreInter.updatePos(deltaTime, cam);
}

bool UI::isMainMenu() const
{
    return m_mainMenu;
}

void UI::mainMenu(sf::RenderWindow& window, const sf::Time& deltaTime)
{
    auto selection = vertiMenuNavigator(m_menuInter.getSelection(), deltaTime);

    if(selection == 0)
    {
        m_mainMenu = false;
    }
    if(selection == 1)
    {
        window.close();
    }
}

unsigned UI::vertiMenuNavigator(const vector<sf::Text>& menu,
                                const sf::Time& deltaTime)
{
    m_currMenuT += deltaTime;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        auto bottomOfMenu = ((menu.end() - 1)->getPosition().y - 2);

        if((m_keyUp || m_currMenuT > m_selectDelay) &&
            m_selectArrow.getPosition().y != bottomOfMenu )
        {
            auto distBetwChoice = ((menu[m_numChoices + 1]).getPosition().y) -
                                   (menu[m_numChoices].getPosition().y);

            m_selectArrow.move(0, distBetwChoice);
            m_numChoices++;

            m_keyUp = false;
            m_currMenuT = sf::Time::Zero;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        auto topOfMenu = menu.begin()->getPosition().y - 2;

        if((m_keyUp || m_currMenuT > m_selectDelay) &&
            m_selectArrow.getPosition().y != topOfMenu)
        {
            auto distBetwChoice = ((menu[m_numChoices - 1]).getPosition().y) -
                                   (menu[m_numChoices].getPosition().y);

            m_selectArrow.move(0, distBetwChoice);
            m_numChoices--;

            m_keyUp = false;
            m_currMenuT = sf::Time::Zero;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        return m_numChoices;
    }

    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
        !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        !m_keyUp)
    {
        m_keyUp = true;
    }

    return -1;
}

void UI::drawMenu(sf::RenderWindow& window)
{
    if(m_mainMenu)
    {
        window.draw(m_selectArrow);
        m_menuInter.draw(window);
    }
}

void UI::drawIngame(sf::RenderWindow& window)
{
    m_roundInter.draw(window);
    m_playerInter.draw(window);
    m_scoreInter.draw(window);
}
