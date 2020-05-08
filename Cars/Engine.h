#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "GameStateManager.h"

class Engine
{
public:
	Engine(sf::RenderWindow& window);

	void Run();
private:
	sf::RenderWindow& m_window;
	sf::Event m_event;
	sf::Clock m_clock;

	ResourceHolder m_resourceManager;
	GameStateManager m_stateManager;
};

