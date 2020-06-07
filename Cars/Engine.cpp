#include "Engine.h"
#include "MainMenuState.h"
#include <iostream>

Engine* Engine::s_instance = nullptr;

Engine::Engine()
	:m_event(sf::Event())
{
}

Engine::~Engine()
{
	std::cout << "Engine gone...\n";
}

Engine* Engine::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new Engine();
	}

	return s_instance;
}

bool Engine::Init(unsigned x, unsigned y, unsigned width, unsigned height, bool fullscreen, const std::string& title)
{
	if (fullscreen)
		m_window.create(sf::VideoMode(width, height), title, sf::Style::None);
	else
		m_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	if (!m_window.isOpen())
		return false;

	sf::Image pic;
	pic.loadFromFile("Textures/Cars title menu.png");
	m_window.setIcon(pic.getSize().x, pic.getSize().y, pic.getPixelsPtr());

	m_stateManager.PushState(new MainMenuState(m_resourceManager, m_stateManager));

	m_music.Play();

	return true;
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

void Engine::Quit()
{
	m_window.close();
	delete s_instance;
}
