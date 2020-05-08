#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

void MainMenuState::HandleInput(sf::RenderWindow& window, sf::Event& events)
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

void MainMenuState::Update(sf::RenderWindow& window, const float dt)
{
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	window.clear();

	window.display();
}