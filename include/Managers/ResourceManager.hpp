#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Thor/Animation.hpp>

//STD
#include <map>
#include <string>
#include <memory>
#include <iostream>

//SELF

typedef std::map<std::string, std::shared_ptr<sf::Texture>> texMap;
typedef std::pair<std::string, std::shared_ptr<sf::Texture>> texPair;

typedef std::map<std::string, std::shared_ptr<sf::Font>> fontMap;
typedef std::pair<std::string, std::shared_ptr<sf::Font>> fontPair;

typedef std::map<std::string, std::shared_ptr<thor::FrameAnimation>> frameAnimationMap;
typedef std::pair<std::string, std::shared_ptr<thor::FrameAnimation>> frameAnimationPair;

typedef std::map<std::string, std::shared_ptr<sf::SoundBuffer>> sBufferMap;
typedef std::pair<std::string, std::shared_ptr<sf::SoundBuffer>> sBufferPair;

class ResourceManager
{
public:

    ResourceManager();
    ~ResourceManager();

    sf::Texture& texture(std::string);
    sf::Font& font(std::string);
    sf::SoundBuffer& soundBuffer(std::string);
    thor::FrameAnimation& frameAnimation(std::string);
    void addFrame(std::string frameAnimation, sf::Time duration, sf::IntRect);

    static thor::Animator<sf::Sprite, std::string> animator;

private:
    static texMap m_textures;
    static fontMap m_fonts;
    static sBufferMap m_sBuffers;
    static frameAnimationMap m_frameAnimations;
};

#endif
