#include "ResourceHolder.h"

ResourceHolder* ResourceHolder::s_instance = nullptr;

ResourceHolder::ResourceHolder()
    :m_textures()
{
}

ResourceHolder* ResourceHolder::GetInstance()
{
    if (s_instance == nullptr)
    {
        s_instance = new ResourceHolder();
    }

    return s_instance;
}

void ResourceHolder::Quit()
{
    delete s_instance;
}

sf::Texture& ResourceHolder::getTexture(std::string path)
{
    const auto& pairFound = m_textures.find(path);
    if (pairFound != m_textures.end())
    {

        return pairFound->second;
    }
    else
    {
        auto& texture = m_textures[path];
        texture.loadFromFile(path);
        return texture;
    }
}

sf::Font& ResourceHolder::getFont(std::string path)
{
    const auto& pairFound = m_fonts.find(path);
    if (pairFound != m_fonts.end())
    {

        return pairFound->second;
    }
    else
    {
        auto& font = m_fonts[path];
        font.loadFromFile(path);
        return font;
    }
}

//No error checking on the buffer!
sf::SoundBuffer& ResourceHolder::getSound(std::string path)
{
    auto pairFound = m_sounds.find(path);
    if (pairFound != m_sounds.end())
    {
        return pairFound->second;
    }
    else
    {

        auto& sBuffer = m_sounds[path];
        sBuffer.loadFromFile(path);
        return sBuffer;
    }
}

