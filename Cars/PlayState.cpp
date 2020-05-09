#include "PlayState.h"

void PlayState::LoadTiles()
{
	m_tile = new Tile(m_resourceManger.getTexture("Textures/grass.jpg"));
}

PlayState::PlayState(ResourceHolder& resourceManger)
	:m_resourceManger(resourceManger)
{
	LoadTiles();
}

PlayState::~PlayState()
{
	delete m_tile;
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

void PlayState::Update(sf::RenderWindow& window, const float dt)
{
}

void PlayState::Render(sf::RenderWindow& window)
{
	window.clear();

	m_tile->Draw(250.f, 250.f, window);

	window.display();
}