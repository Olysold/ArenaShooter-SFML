#include "UI/UIscore.hpp"
#include "util.hpp"
#include "Movement.hpp"

#include <sstream>
using std::ostringstream;

#include <iomanip>
using std::setw;
using std::setfill;

ResourceManager UIscore::m_resMan;

UIscore::UIscore()
{
    m_textDisplay.setFont(m_resMan.font("CenturyGothic"));
    m_textDisplay.setCharacterSize(30);
}

void UIscore::setPos(const Camera& cam)
{
    ///Setting up score interface
    sf::Vector2f camCenter = cam.getCamera().getCenter();
    auto posX = camCenter.x - 380;
    auto posY = camCenter.y - 280;

    m_textDisplay.setPosition(posX, posY);
}

void UIscore::updatePos(const sf::Time& deltaTime, const Camera& cam)
{
    sf::Vector2f camCenter = cam.getCamera().getCenter();
    auto camX = camCenter.x - 380;
    auto camY = camCenter.y - 280;

    auto textX = m_textDisplay.getPosition().x;
    auto textY = m_textDisplay.getPosition().y;

    if(textX != camX)
    {
        auto distance = camX - textX;

        Movement::moveHoriNoTime(m_textDisplay, distance);
    }
    if(textY != camY)
    {
        auto distance = camY - textY;

        Movement::moveVertiNoTime(m_textDisplay, distance);
    }
}

void UIscore::updateScore(const EnemyManager& eneMan)
{
    unsigned int numScore = eneMan.getTotalScore();

    ostringstream oss;

    oss << setw(6) << setfill('0') << numScore;
    m_strScore = oss.str();

    m_textDisplay.setString(m_strScore);
}

void UIscore::draw(sf::RenderWindow& window)
{
    window.draw(m_textDisplay);
}
