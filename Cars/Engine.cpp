#include "Engine.h"
#include "MainMenuState.h"

Engine::Engine(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event())
{
	/* window icon! */
	sf::Image pic;
	pic.loadFromFile("Textures/Cars title menu.png");
	m_window.setIcon(pic.getSize().x, pic.getSize().y, pic.getPixelsPtr());

	m_stateManager.PushState(new MainMenuState(m_resourceManager, m_stateManager));

	m_music.Play();
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

		if (m_music.GetCurrentSong().getStatus() == sf::Music::Stopped)
		{
			m_music.Play();
		}

	}
}