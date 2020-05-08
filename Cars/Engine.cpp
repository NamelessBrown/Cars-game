#include "Engine.h"

Engine::Engine(sf::RenderWindow& window)
	:m_window(window)
{
}

void Engine::Run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.display();
	}
}
