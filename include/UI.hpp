#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED

//3rd
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <vector>
#include <string>

//Self
#include "ResourceManager.hpp"
#include "util.hpp"

class UI
{
public:
    UI();

    void update(sf::Time&);

    ///Menu functions
    bool isMainMenu() const;
    void mainMenu(const unsigned, sf::RenderWindow&);

    //Only thing hardcoded is the arrow indicator and the distance between it and the text itself
    unsigned vertiMenuNavigator(const std::string, sf::Time);
    void drawMainMenu(sf::RenderWindow&);
    void drawRoundDelay(sf::RenderWindow&);

private:
    //Where we are in the game
    bool        m_mainMenu;

    //Round delays
    bool        m_delay;
    std::string m_roundStr;
    sf::Text    m_roundTxt;
    sf::Time    m_currRoundT;
    sf::Time    m_roundDelayT;
    unsigned    m_roundNum;
    float       m_opacity;

    //Scrolling selection controls
    bool        m_keyUp;
    sf::Time    m_currMenuT;
    sf::Time    m_selectDelay;

    std::map<std::string, std::vector<sf::Text>> m_textMap;
    unsigned    m_numChoices;
    sf::Sprite  m_selectArrow;
    static ResourceManager m_resMan;
};

#endif // UI_HPP_INCLUDED
