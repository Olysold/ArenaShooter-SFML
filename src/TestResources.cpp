#include "TestResources.hpp"

TestResources::texMap TestResources::m_textures;
TestResources::fontMap TestResources::m_fonts;
TestResources::aniMap TestResources::m_animations;
TestResources::sBufferMap TestResources::m_sBuffers;

TestResources::TestResources()
{
}


sf::Texture& TestResources::texture(std::string filename)
{
    if (m_textures.find(filename) != m_textures.end())
    {
        return *m_textures.find(filename)->second;
    }
    else
    {
        std::shared_ptr<sf::Texture> t(new sf::Texture);

        if (!t->loadFromFile(("data/textures/" + filename + ".png")))
        {
            filename = "Error";
            if (!t->loadFromFile("data/textures/Error.png"))
            {
                std::cout << "Unable to find backup texture, exiting\n";
                exit(EXIT_FAILURE);
            }
        }
        std::cout << "Added texture \'" << filename << ".png\'\n";
        m_textures.insert(texPair(filename, t));

        return *m_textures.find(filename)->second;
    }
}

sf::Font& TestResources::font(std::string filename)
{
    if (m_fonts.find(filename) != m_fonts.end())
    {
        return *m_fonts.find(filename)->second;
    }
    else
    {
        std::shared_ptr<sf::Font> f(new sf::Font);

        if (!f->loadFromFile(("data/fonts/" + filename + ".ttf")))
        {
            filename = "arial";
            if (!f->loadFromFile("data/fonts/arial.ttf"))
            {
                std::cout << "Unable to find backup font, exiting\n";
                filename = "Error";
                exit(EXIT_FAILURE);
            }
        }
        std::cout << "Added font \'" << filename << ".ttf\'\n";
        m_fonts.insert(fontPair(filename, f));
        return *m_fonts.find(filename)->second;
    }
}

sf::SoundBuffer& TestResources::soundBuffer(std::string filename)
{
    if (m_sBuffers.find(filename) != m_sBuffers.end())
    {
        return *m_sBuffers.find(filename)->second;
    }
    else
    {
        std::shared_ptr<sf::SoundBuffer> sb(new sf::SoundBuffer);

        if (!sb->loadFromFile(("data/sounds/" + filename + ".ogg")))
        {
            filename = "Error";
            if (!sb->loadFromFile("data/sounds/Error.ogg"))
            {
                std::cout << "Unable to find backup font, exiting\n";
                exit(EXIT_FAILURE);
            }
        }
        std::cout << "Added sound \'" << filename << ".ogg\'\n";
        m_sBuffers.insert(sBufferPair(filename, sb));
        return *m_sBuffers.find(filename)->second;
    }
}

Animation& TestResources::addAnimation(std::string name, Animation ani)
{
    if (m_animations.find(name) != m_animations.end())
    {
        return *m_animations.find(name)->second;
    }
    else
    {
        std::shared_ptr<Animation> a(new Animation);
        *a = ani;

        std::cout << "Added animation \'" << name << "\'\n";
        m_animations.insert(aniPair(name, a));
        return *m_animations.find(name)->second;
    }
}

Animation& TestResources::getAnimation(std::string name)
{
    if (m_animations.find(name) != m_animations.end())
    {
        return *m_animations.find(name)->second;
    }
    else
    {
        std::cout << "Unable to find animation \'" << name << "\', exiting\n";
        exit(EXIT_FAILURE);
    }
}
