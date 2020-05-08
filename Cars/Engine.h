#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Engine
{
public:
	Engine(sf::RenderWindow& window);
	void Run();
private:
	sf::RenderWindow& m_window;
};

