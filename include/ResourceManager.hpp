#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STD
#include <map>
#include <string>
#include <memory>
#include <iostream>

//SELF
#include "Animation.hpp"

typedef std::map<std::string, std::shared_ptr<sf::Texture>> texMap;
typedef std::pair<std::string, std::shared_ptr<sf::Texture>> texPair;

typedef std::map<std::string, std::shared_ptr<sf::Font>> fontMap;
typedef std::pair<std::string, std::shared_ptr<sf::Font>> fontPair;

typedef std::map<std::string, std::shared_ptr<Animation>> aniMap;
typedef std::pair<std::string, std::shared_ptr<Animation>> aniPair;

typedef std::map<std::string, std::shared_ptr<sf::SoundBuffer>> sBufferMap;
typedef std::pair<std::string, std::shared_ptr<sf::SoundBuffer>> sBufferPair;

class ResourceManager
{
public:

    ResourceManager();
    ~ResourceManager();

    std::shared_ptr<sf::Texture> texture(std::string);
    std::shared_ptr<sf::Font> font(std::string);
    sf::SoundBuffer* soundBuffer(std::string);

    Animation* addAnimation(std::string, Animation);
    Animation* getAnimation(std::string);

private:
    static texMap m_textures;
    static fontMap m_fonts;
    static aniMap m_animations;
    static sBufferMap m_sBuffers;
};

#endif
