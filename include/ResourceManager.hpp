#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//STD
#include <map>
#include <string>
#include <memory>
#include <iostream>

//3RD
#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Texture*> texMap;
typedef std::map<std::string, sf::Font*> fontMap;
typedef std::pair<std::string, sf::Texture*> texPair;
typedef std::pair<std::string, sf::Font*> fontPair;

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    sf::Texture* texture(std::string);
    sf::Font* font(std::string);
private:
    static texMap m_textures;
    static fontMap m_fonts;
};

#endif
