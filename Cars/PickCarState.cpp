#include "PickCarState.h"

PickCarState::PickCarState()
	:m_leftButton({250.f, 150.f}, ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"), 
		ResourceHolder::GetInstance()->getTexture("Textures/left arrow.png"), 12),
	m_rightButton({1150.f, 150.f}, ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"),
		ResourceHolder::GetInstance()->getTexture("Textures/right arrow.png"), 12),
	m_currentCar({750.f, 450.f}, ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"),  
		ResourceHolder::GetInstance()->getTexture("Textures/current car.png"), 12)
{
	m_leftButton.SetScale(6);
	m_rightButton.SetScale(2);
	m_currentCar.SetScale(10);
	m_leftButton.SetText("");
	m_rightButton.SetText("");
	m_currentCar.SetText("");

	m_Cars.setTexture(ResourceHolder::GetInstance()->getTexture("Textures/cars.jpg"));
	m_textureRect = sf::IntRect(800, 0, 225, 156);
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
					m_textureRect.top += 156;
					//m_top += 97;
					m_Cars.setTextureRect(m_textureRect);
				}

				if (m_leftButton.IsClicked(sf::Mouse::getPosition(window)))
				{
					m_textureRect.top -= 156;
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
		GameStateManager::GetInstance()->ChangeState(new PlayState(m_textureRect));
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
