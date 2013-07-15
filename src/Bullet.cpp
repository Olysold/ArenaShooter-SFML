#include "Bullet.hpp"

#include <cmath>

Bullet::Bullet(sf::Vector2f pos,
               float rotation,
               unsigned int speed,
               int damage):
m_speed(speed),
m_damage(damage)
{
    sprite.setPosition(pos);
    sprite.setRotation(rotation);
}

void Bullet::update(sf::Time& deltaTime)
{
    /*
        double rad = zge::degToRad(disp->sprite.getRotation());

        double sinRad = std::sin(rad);
        double cosRad = std::cos(rad);

        if (m_Ents[i]->hasComp<Flags>() && m_Ents[i]->comp<Flags>()->flags.test(constant::Flag::Player))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                mov->velocity.x = 20 * sinRad * mov->acceleration * argDT;
                mov->velocity.y = 20 * -1 * cosRad * mov->acceleration * argDT;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                mov->velocity.x = 20 * -1 * sinRad * mov->acceleration * argDT;
                mov->velocity.y = 20 * cosRad * mov->acceleration * argDT;
            }
    */

    float sinMove = std::sin((sprite.getRotation() / 180.f) * 3.141592653);
    float cosMove = std::cos((sprite.getRotation() / 180.f) * 3.141592653);

    if (sprite.getRotation() <= 0)
    {
        sprite.move(m_speed * -1 * sinMove * deltaTime.asSeconds(), m_speed * cosMove * deltaTime.asSeconds());
    }
    else if (sprite.getRotation() > 0)
    {
        sprite.move(m_speed * sinMove * deltaTime.asSeconds(), m_speed * -1 * cosMove * deltaTime.asSeconds());
    }
    else
    {
        std::cout << "ERROR\n";
    }
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Bullet::getDamage()
{
    return m_damage;
}
