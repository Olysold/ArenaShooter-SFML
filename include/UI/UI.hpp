#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED

//3rd
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <vector>
#include <string>

//Self
#include "Managers/ResourceManager.hpp"
#include "Managers/EnemyManager.hpp"
#include "Player.hpp"
#include "Camera.hpp"
#include "UIplayer.hpp"
#include "UIroundTitles.hpp"
#include "UImenu.hpp"
#include "UIscore.hpp"

class Camera;

class UI
{
public:
    UI(const Player&, const Camera&);

    void update(const sf::Time&, const Player&, const EnemyManager&, const Camera&);

    ///Menu functions
    bool isMainMenu() const;
    void mainMenu(sf::RenderWindow&, const sf::Time&);

    unsigned vertiMenuNavigator(const std::vector<sf::Text>&,
                                const sf::Time&);

    void drawMenu(sf::RenderWindow&);
    void drawIngame(sf::RenderWindow&);

private:
    UIroundTitles m_roundInter;
    UIplayer      m_playerInter;
    UImenu        m_menuInter;
    UIscore       m_scoreInter;

    //Where we are in the game
    bool        m_mainMenu;

    //Scrolling selection controls
    bool        m_keyUp;
    sf::Time    m_currMenuT;
    sf::Time    m_selectDelay;

    unsigned    m_numChoices;
    sf::Sprite  m_selectArrow;
    static ResourceManager m_resMan;
};

#endif // UI_HPP_INCLUDED
