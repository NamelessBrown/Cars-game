#include "PickCarState.h"

PickCarState::PickCarState(ResourceHolder& resources, GameStateManager& gameStateRef)
	:m_resourceRef(resources), m_leftButton({150.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/left arrow.png"), 12),
	m_rightButton({750.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/right arrow.png"), 12),
	m_currentCar({500.f, 500.f}, resources.getFont("Font/NovaMono.ttf"),  resources.getTexture("Textures/current car.png"), 12),
	m_gameStateManagerRef(gameStateRef)
{
	m_leftButton.SetScale(6);
	m_rightButton.SetScale(2);
	m_currentCar.SetScale(6);
	m_leftButton.SetText("");
	m_rightButton.SetText("");
	m_currentCar.SetText("");

	m_Cars.setTexture(m_resourceRef.getTexture("Textures/Cars.jpg"));
	m_Cars.setPosition(300.f, 300.f);
}

PickCarState::~PickCarState()
{
}

void PickCarState::HandleInput(sf::RenderWindow& window, sf::Event& events)
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

void PickCarState::Update(sf::RenderWindow& window, const float dt)
{
	if (m_currentCar.IsClicked(sf::Mouse::getPosition(window)))
	{
		m_gameStateManagerRef.PushState(new PlayState(m_resourceRef));
	}
}

void PickCarState::Render(sf::RenderWindow& window)
{
	window.clear();

	m_leftButton.Draw(window);
	m_rightButton.Draw(window);
	m_currentCar.Draw(window);

	window.draw(m_Cars);
	window.display();
}
