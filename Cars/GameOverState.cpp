#include "GameOverState.h"
#include "MainMenuState.h"

GameOverState::GameOverState(ResourceHolder& resources, GameStateManager& gameStateManager)
	:m_gameStateManager(gameStateManager), m_resourceMananger(resources), m_playAgainButton({250.f, 250.f}, 
		resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/upgradeSpeed.png"), 50),
	m_quitButton({350.f, 350.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/upgradeSpeed.png"), 50)
{
	m_playAgainButton.SetText("Play again?");
	m_playAgainButton.SetScale(6.f);
	m_quitButton.SetText("Quit");
	m_quitButton.SetScale(6.f);
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
	if (m_playAgainButton.IsClicked(sf::Mouse::getPosition(window)))
	{
		m_gameStateManager.ChangeState(new MainMenuState(m_resourceMananger, m_gameStateManager));
	}

	if (m_quitButton.IsClicked(sf::Mouse::getPosition(window)))
	{
		window.close();
	}

}

void GameOverState::Render(sf::RenderWindow& window)
{
	window.clear();

	m_playAgainButton.Draw(window);
	m_quitButton.Draw(window);

	window.display();
}

