#include "ResourceManager.hpp"

texMap ResourceManager::m_textures;
fontMap ResourceManager::m_fonts;

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
