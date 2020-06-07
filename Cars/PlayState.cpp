#include "PlayState.h"
#include <iostream>
#include "GameOverState.h"
#include "Collision.h"

PlayState::PlayState(sf::IntRect& textureRect)
	:m_player(ResourceHolder::GetInstance()->getTexture("Textures/cars.jpg"), textureRect,
		ResourceHolder::GetInstance()->getFont("Font/NovaMono.ttf"), ResourceHolder::GetInstance()->getTexture("Textures/upgradeSpeed.png")),
	m_backgroundScroll(.5f), m_backgroundScrollSpeed(.5f)
{
	m_background.setTexture(ResourceHolder::GetInstance()->getTexture("Textures/road.jpg"));
	m_background.setPosition(300.f, 0.f);

	SpawnBomb(5);
	SpawnPowerup(1);
}

PlayState::~PlayState()
{

}


void PlayState::HandleInput(sf::RenderWindow& window, sf::Event& events)
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

void PlayState::MoveBackground(const float dt)
{
	m_backgroundScroll = std::fmod((m_backgroundScroll + m_backgroundScrollSpeed * dt), 75);
	m_background.setPosition(300.f, -(float)m_backgroundScroll);
}

void PlayState::SpawnBomb(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		m_bombs.emplace_back(Bombs(ResourceHolder::GetInstance()->getTexture("Textures/bomb.png")));
	}
}

void PlayState::SpawnPowerup(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		m_powerups.emplace_back(Powerup(ResourceHolder::GetInstance()->getTexture("Textures/powerup.png")));
	}
}

void PlayState::Collision()
{
	for(unsigned i = 0; i < m_bombs.size(); i++)
	{
		if (Collision::AxisAlignedBoundingBox(m_player.GetSprite(), m_bombs[i].GetSprite()))
		{
			m_player.LoseHealth(m_bombs[i].GetDamage());
			m_bombs.erase(m_bombs.begin() + i);
		}
	}

	for (unsigned i = 0; i < m_powerups.size(); i++)
	{
		if (Collision::AxisAlignedBoundingBox(m_player.GetSprite(), m_powerups[i].GetSprite()))
		{
			m_player.GainPowerup(m_powerups[i].GetSpeed());
			m_powerups.erase(m_powerups.begin() + i);
		}
	}

}

void PlayState::Update(sf::RenderWindow& window, const float dt)
{
	if (!m_player.isDead())
	{
		for (unsigned i = 0; i < m_bombs.size(); i++) //Bombs update first
		{
			m_bombs[i].Update(dt);

			if (m_bombs[i].GetSprite().getPosition().y > 720)
			{
				m_player.GainPoints(m_bombs[i].GetDamage()); //Points are earn by the damage of the bomb
				m_bombs.erase(m_bombs.begin() + i);
			}

		}

		for (unsigned i = 0; i < m_powerups.size(); i++) //powerups update second
		{
			m_powerups[i].Update(dt);

			if (m_powerups[i].GetSprite().getPosition().y > 720)
			{
				m_powerups.erase(m_powerups.begin() + i);
			}

		}

		m_player.Update(window, dt);
		MoveBackground(dt);

		Collision();

		if (m_bombs.size() < 3) 
		{
			SpawnBomb(4);
		}

		if (m_powerups.size() <= 0)
		{
			SpawnPowerup(1);
		}

	}
	else
	{
		GameStateManager::GetInstance()->ChangeState(new GameOverState());
	}
}

void PlayState::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_background);
	m_player.Render(window);

	for (auto& e : m_bombs)
	{
		e.Render(window);
	}

	for (auto& e : m_powerups)
	{
		e.Render(window);
	}

	window.display();
}