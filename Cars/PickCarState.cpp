#include "PickCarState.h"

PickCarState::PickCarState(ResourceHolder& resources)
	:m_resourceRef(resources), m_leftButton({150.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/left arrow.png"), 12),
	m_rightButton({750.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/right arrow.png"), 12)
{
	m_leftButton.SetScale(6);
	m_rightButton.SetScale(2);
	m_leftButton.SetText("");
	m_rightButton.SetText("");

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
}

void PickCarState::Render(sf::RenderWindow& window)
{
	window.clear();

	m_leftButton.Draw(window);
	m_rightButton.Draw(window);

	window.draw(m_Cars);
	window.display();
}
