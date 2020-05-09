#include "PlayState.h"

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
	window.clear(sf::Color::Blue);

	window.display();
}