#include "PlayState.h"
#include <iostream>

PlayState::PlayState(ResourceHolder& resourceManger, sf::IntRect& textureRect)
	:m_resourceManger(resourceManger), m_player(m_resourceManger.getTexture("Textures/cars.jpg"), textureRect), 
	m_backgroundScroll(.5f), m_backgroundScrollSpeed(.5f)
{
	m_background.setTexture(m_resourceManger.getTexture("Textures/road.jpg"));
	m_background.setPosition(300.f, 0.f);
}

PlayState::~PlayState()
{

}


void PlayState::HandleInput(sf::RenderWindow& window, sf::Event& events)
{
	while (window.pollEvent(events))
	{
		switch (events.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (events.key.code == sf::Keyboard::Escape)
				window.close();
			break;
		default:
			break;
		}
	}
}

void PlayState::MoveBackground(const float dt)
{
	m_backgroundScroll = std::fmod((m_backgroundScroll + m_backgroundScrollSpeed * dt), 75);
	m_background.setPosition(300.f, -(float)m_backgroundScroll);
}

void PlayState::Update(sf::RenderWindow& window, const float dt)
{
	m_player.Update(dt);
	MoveBackground(dt);
}

void PlayState::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_background);
	m_player.Render(window);

	window.display();
}