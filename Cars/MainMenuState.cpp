#include "MainMenuState.h"
#include "ResourceHolder.h"
#include "GameStateManager.h"

MainMenuState::MainMenuState()
	:m_startButton(sf::Vector2f(0.f, 250.f), ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"), 
		ResourceHolder::GetInstance()->getTexture("Textures/start.png"), 25),
	m_quitButton(sf::Vector2f(0.f, 325.0f), ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"), 
		ResourceHolder::GetInstance()->getTexture("Textures/quit.png"), 25)
{

	m_startButton.SetScale(6.f);
	m_quitButton.SetScale(2.f);
	m_startButton.SetText("");
	m_quitButton.SetText("");

	m_background.setTexture(ResourceHolder::GetInstance()->getTexture("Textures/Cars title menu.png"));
	m_background.setPosition(540.f, 160.f);
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
		GameStateManager::GetInstance()->ChangeState(new PickCarState());
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

	window.draw(m_background);

	window.display();
}