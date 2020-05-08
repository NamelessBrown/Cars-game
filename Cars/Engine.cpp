#include "Engine.h"

Engine::Engine(sf::RenderWindow& window)
	:m_window(window), m_stateManager(m_window)
{
}

void Engine::Run()
{
	while (m_window.isOpen())
	{
		float dt = m_clock.restart().asSeconds() * 60.f;
		Update(dt);
		Render();
	}
}

void Engine::Update(float dt)
{
}

void Engine::Render()
{
}
