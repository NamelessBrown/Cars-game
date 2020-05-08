#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "GameStateManager.h"

class Engine
{
public:
	Engine(sf::RenderWindow& window);

	void Run();
	void Update(float dt);
	void Render();
private:
	sf::RenderWindow& m_window;
	sf::Clock m_clock;

	ResourceHolder m_resourceManager;
	GameStateManager m_stateManager;
};

