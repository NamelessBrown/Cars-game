#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceHolder
{
public:
	static ResourceHolder* GetInstance();
	void Quit();
	sf::Texture& getTexture(std::string path);
	sf::Font& getFont(std::string path);
	sf::SoundBuffer& getSound(std::string path);
private:
	ResourceHolder();

	static ResourceHolder* s_instance;

	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
	std::map<std::string, sf::SoundBuffer> m_sounds;
};

