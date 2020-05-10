#include "PlayState.h"

PlayState::PlayState(ResourceHolder& resourceManger)
	:m_resourceManger(resourceManger)
{
	m_background.setTexture(m_resourceManger.getTexture("Textures/ground.jpg"));
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

void PlayState::Update(sf::RenderWindow& window, const float dt)
{
}

void PlayState::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_background);

	window.display();
}