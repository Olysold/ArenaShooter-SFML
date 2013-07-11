#include "ResourceManager.hpp"

texMap ResourceManager::m_textures;
fontMap ResourceManager::m_fonts;
aniMap ResourceManager::m_animations;
sBufferMap ResourceManager::m_sBuffers;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (texMap::iterator it = m_textures.begin(); it != m_textures.end(); ++it)
    {
        delete it->second;
    }
}

sf::Texture* ResourceManager::texture(std::string filename)
{
    if (m_textures.find(filename) != m_textures.end())
    {
        return m_textures.find(filename)->second;
    }
    else
    {
        sf::Texture* t = new sf::Texture;

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

        return m_textures.find(filename)->second;
    }
}

sf::Font* ResourceManager::font(std::string filename)
{
    if (m_fonts.find(filename) != m_fonts.end())
    {
        return m_fonts.find(filename)->second;
    }
    else
    {
        sf::Font* f = new sf::Font;

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
        return m_fonts.find(filename)->second;
    }
}

sf::SoundBuffer* ResourceManager::soundBuffer(std::string filename)
{
    if (m_sBuffers.find(filename) != m_sBuffers.end())
    {
        return m_sBuffers.find(filename)->second;
    }
    else
    {
        sf::SoundBuffer* sb = new sf::SoundBuffer;

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
        return m_sBuffers.find(filename)->second;
    }
}

Animation* ResourceManager::addAnimation(std::string name, Animation ani)
{
    if (m_animations.find(name) != m_animations.end())
    {
        return m_animations.find(name)->second;
    }
    else
    {
        Animation* a = new Animation;
        *a = ani;
        std::cout << "Added animation \'" << name << "\'\n";
        m_animations.insert(aniPair(name, a));
        return m_animations.find(name)->second;
    }
}

Animation* ResourceManager::getAnimation(std::string name)
{
    if (m_animations.find(name) != m_animations.end())
    {
        return m_animations.find(name)->second;
    }
    else
    {
        std::cout << "Unable to find animation \'" << name << "\', exiting\n";
        exit(EXIT_FAILURE);
    }
}
