#include "Bullet.hpp"

#include <cmath>
#include "util.hpp"

Bullet::Bullet(sf::Vector2f pos,
               float rotation,
               unsigned int speed,
               int damage,
               sf::Texture& tex):
m_speed(speed),
m_damage(damage)
{
    sprite.setTexture(tex);
    sprite.setPosition(pos);
    sprite.setRotation(rotation);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
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

    //These guys will have values between 0 and 1, determining the amount to move on each axis based on rotation.
    float sinMove = std::sin(util::degToRad(sprite.getRotation()));
    float cosMove = std::cos(util::degToRad(sprite.getRotation()));

    if (sprite.getRotation() <= 0) //Facing south
    {
        sprite.move(m_speed * -1 * sinMove * deltaTime.asSeconds(), m_speed * cosMove * deltaTime.asSeconds());
    }
    else if (sprite.getRotation() > 0) //Facing north
    {
        sprite.move(m_speed * sinMove * deltaTime.asSeconds(), m_speed * -1 * cosMove * deltaTime.asSeconds());
    }
    else
    {
        //Dunno why I put this here, can probably delete.
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
