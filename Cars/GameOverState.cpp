#include "GameOverState.h"

GameOverState::GameOverState(ResourceHolder& resources, GameStateManager& gameStateManager)
	:m_gameStateManager(gameStateManager), m_resourceMananger(resources)
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::HandleInput(sf::RenderWindow& window, sf::Event& events)
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

void GameOverState::Update(sf::RenderWindow& window, const float dt)
{
}

void GameOverState::Render(sf::RenderWindow& window)
{
	window.clear();

	window.display();
}

