#include "Engine.h"
#include "MainMenuState.h"

Engine::Engine(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event())
{
	m_stateManager.PushState(new MainMenuState(m_resourceManager, m_stateManager));
}

Engine::~Engine()
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