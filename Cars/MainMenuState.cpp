#include "MainMenuState.h"

MainMenuState::MainMenuState(ResourceHolder& textureManger, GameStateManager& states)
	:m_startButton(sf::Vector2f(0.f, 250.f), textureManger.getFont("Font/NovaMono.ttf"), textureManger.getTexture("Textures/start.png"), 25),
	m_quitButton(sf::Vector2f(0.f, 325.0f), textureManger.getFont("Font/NovaMono.ttf"), textureManger.getTexture("Textures/quit.png"), 25),
	m_stateManagerRef(states), m_resourceManagerRef(textureManger)
{
	m_startButton.SetScale(6.f);
	m_quitButton.SetScale(2.f);

	m_startButton.SetText("");
	m_quitButton.SetText("");
}

MainMenuState::~MainMenuState()
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
	if (m_startButton.IsClicked(sf::Mouse::getPosition(window)))
	{
		m_stateManagerRef.PushState(new PlayState(m_resourceManagerRef));
	}

	if (m_quitButton.IsClicked(sf::Mouse::getPosition(window)))
	{
		window.close();
	}

}

void MainMenuState::Render(sf::RenderWindow& window)
{
	window.clear();

	m_startButton.Draw(window);
	m_quitButton.Draw(window);

	window.display();
}