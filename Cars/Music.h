#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <random>

class Music
{
public:
	Music();

	const sf::Music& GetCurrentSong() const { return m_music; }

	void Play();

private:
	sf::Music m_music;
	std::vector<std::string> m_songs;

	std::random_device m_rd;
	std::mt19937 m_mt;
	std::uniform_int_distribution<int> m_distribution;

	int m_whatFile;
};

