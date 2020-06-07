#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "GameStateManager.h"
#include "Music.h"

class Engine
{
public:
	~Engine();

	static Engine* GetInstance();

	bool Init(unsigned x, unsigned y, unsigned width, unsigned height, bool fullscreen, const std::string& title);
	void Run();
	void Quit();
private:
	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
private:
	static Engine* s_instance;
	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Clock m_clock;

	ResourceHolder m_resourceManager;
	GameStateManager m_stateManager;

	Music m_music;

};

