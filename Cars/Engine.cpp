#include "Engine.h"

Engine::Engine(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event())
{
}

void Engine::Run()
{
	while (m_window.isOpen())
	{
		float dt = m_clock.restart().asSeconds() * 60.f;
		m_stateManager.CurrentState()->HandleInput(m_window, m_event);
		m_stateManager.CurrentState()->Update(m_window, dt);
		m_stateManager.CurrentState()->Render(m_window);
	}
}