#include "PlayState.h"
#include <iostream>
#include "GameOverState.h"
#include "Collision.h"

PlayState::PlayState(ResourceHolder& resourceManger, sf::IntRect& textureRect, GameStateManager& gameStateManager)
	:m_resourceManger(resourceManger), m_player(m_resourceManger.getTexture("Textures/cars.jpg"), textureRect, resourceManger.getFont("Font/NovaMono.ttf")), 
	m_backgroundScroll(.5f), m_backgroundScrollSpeed(.5f), m_gameStateManager(gameStateManager)
{
	m_background.setTexture(m_resourceManger.getTexture("Textures/road.jpg"));
	m_background.setPosition(300.f, 0.f);

	SpawnBomb(5);
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
		m_bombs.emplace_back(Bombs(m_resourceManger.getTexture("Textures/bomb.png")));
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
				m_bombs.erase(m_bombs.begin() + i);
			}

		}

		m_player.Update(dt);
		MoveBackground(dt);

		Collision();

		if (m_bombs.size() < 3) 
		{
			SpawnBomb(4);
		}

	}
	else
	{
		m_gameStateManager.PushState(new GameOverState(m_resourceManger, m_gameStateManager));
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

	window.display();
}