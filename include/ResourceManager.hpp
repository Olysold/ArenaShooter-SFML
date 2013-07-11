#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <string>
#include <memory>
#include <iostream>

//SELF
#include "Animation.hpp"

class ResourceManager
{
public:
    typedef std::map<std::string, sf::Texture*> texMap;
    typedef std::pair<std::string, sf::Texture*> texPair;

    typedef std::map<std::string, sf::Font*> fontMap;
    typedef std::pair<std::string, sf::Font*> fontPair;

    typedef std::map<std::string, Animation*> aniMap;
    typedef std::pair<std::string, Animation*> aniPair;

    typedef std::map<std::string, sf::SoundBuffer*> sBufferMap;
    typedef std::pair<std::string, sf::SoundBuffer*> sBufferPair;

    ResourceManager();
    ~ResourceManager();

    sf::Texture* texture(std::string);
    sf::Font* font(std::string);
    sf::SoundBuffer* soundBuffer(std::string);

    Animation* addAnimation(std::string, Animation);
    Animation* getAnimation(std::string);

private:
    static texMap m_textures;
    static fontMap m_fonts;
    static aniMap m_animations;
    static sBufferMap m_sBuffer;
};

#endif
