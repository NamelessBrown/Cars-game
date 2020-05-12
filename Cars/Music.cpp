#include "Music.h"

Music::Music()
	:m_rd(), m_mt(m_rd()), m_distribution(1, 4), m_whatFile(m_distribution(m_mt))
{
	m_songs.emplace_back("Music/Club Diver.ogg");
	m_songs.emplace_back("Music/Movement Proposition.ogg");
	m_songs.emplace_back("Music/The Complex.ogg");
	m_songs.emplace_back("Music/The Lift.ogg");
}

void Music::Play()
{
	m_whatFile = m_distribution(m_mt);
	m_whatFile--;

	m_music.openFromFile(m_songs.at(m_whatFile));

	m_music.play();
}
