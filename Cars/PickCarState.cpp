#include "PickCarState.h"

PickCarState::PickCarState(ResourceHolder& resources, GameStateManager& gameStateRef)
	:m_resourceRef(resources), m_leftButton({250.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/left arrow.png"), 12),
	m_rightButton({1150.f, 150.f}, resources.getFont("Font/NovaMono.ttf"), resources.getTexture("Textures/right arrow.png"), 12),
	m_currentCar({750.f, 450.f}, resources.getFont("Font/NovaMono.ttf"),  resources.getTexture("Textures/current car.png"), 12),
	m_gameStateManagerRef(gameStateRef)
{
	m_leftButton.SetScale(6);
	m_rightButton.SetScale(2);
	m_currentCar.SetScale(10);
	m_leftButton.SetText("");
	m_rightButton.SetText("");
	m_currentCar.SetText("");

	m_Cars.setTexture(m_resourceRef.getTexture("Textures/cars.jpg"));
	m_textureRect = sf::IntRect(100, 50, 130, 225);
	m_Cars.setTextureRect(m_textureRect);
	m_Cars.setScale(m_Cars.getScale() / 2.f);
	m_Cars.setPosition(720.f, 180.f);
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
		case sf::Event::MouseButtonPressed:
			if (events.mouseButton.button == sf::Mouse::Left)
			{
				if (m_rightButton.IsClicked(sf::Mouse::getPosition(window)))
				{
					m_textureRect.left += 250;
					//m_top += 97;
					m_Cars.setTextureRect(m_textureRect);
				}

				if (m_leftButton.IsClicked(sf::Mouse::getPosition(window)))
				{
					m_textureRect.left -= 250;
					//m_top -= 97;
					m_Cars.setTextureRect(m_textureRect);
				}
			}
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
		//TODO: pass the car sprite that is selected to the PlayState
		m_gameStateManagerRef.PushState(new PlayState(m_resourceRef, m_textureRect));
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
