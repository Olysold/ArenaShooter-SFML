#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED

//3rd
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <vector>
#include <string>
#include <memory>

//Self
#include "Managers/ResourceManager.hpp"
#include "Player.hpp"
#include "UIplayer.hpp"
#include "UIroundTitles.hpp"
#include "UImenu.hpp"

class UI
{
public:
    UI(const Player&);

    void update(sf::Time&);

    ///Menu functions
    bool isMainMenu() const;
    void mainMenu(sf::RenderWindow&, const sf::Time&);

    unsigned vertiMenuNavigator(const std::vector<sf::Text>&,
                                const sf::Time&);

    void drawMenu(sf::RenderWindow&);
    void drawIngame(sf::RenderWindow&);

private:
    const std::shared_ptr<const Player> m_ptPlayer;
    UIroundTitles m_roundInter;
    UIplayer    m_playerInter;
    UImenu      m_menuInter;

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
