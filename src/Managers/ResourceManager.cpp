#include "Managers/ResourceManager.hpp"

texMap ResourceManager::m_textures;
fontMap ResourceManager::m_fonts;
sBufferMap ResourceManager::m_sBuffers;
frameAnimationMap ResourceManager::m_frameAnimations;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

sf::Texture& ResourceManager::texture(std::string filename)
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

sf::Font& ResourceManager::font(std::string filename)
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

sf::SoundBuffer& ResourceManager::soundBuffer(std::string filename)
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

thor::FrameAnimation& ResourceManager::frameAnimation(std::string name)
{
    if (m_frameAnimations.find(name) == m_frameAnimations.end())
    {
        std::shared_ptr<thor::FrameAnimation> fa (new thor::FrameAnimation);

        m_frameAnimations.insert(frameAnimationPair(name, fa));
    }

    return *m_frameAnimations.find(name)->second;
}

void ResourceManager::addFrame(std::string aniName, sf::Time duration, sf::IntRect rect)
{
    if (m_frameAnimations.find(aniName) != m_frameAnimations.end())
    {
        m_frameAnimations.find(aniName)->second->addFrame(duration.asSeconds(), rect);
    }
    else
    {
        std::cout << aniName << " not found, frame not added.\n";
    }
}
