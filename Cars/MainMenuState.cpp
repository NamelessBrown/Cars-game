#include "MainMenuState.h"

MainMenuState::MainMenuState(ResourceHolder& textureManger)
	:m_startButton(sf::Vector2f(0.f, 250.f), textureManger.getFont("Font/NovaMono.ttf"), textureManger.getTexture("Textures/start.png"), 25)
{
	m_startButton.SetScale(6.f);
	m_startButton.SetText("");
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

	m_startButton.Draw(window);

	window.display();
}