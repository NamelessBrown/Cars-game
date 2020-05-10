#pragma once

#include "GameState.h"
#include "ResourceHolder.h"
#include "Button.h"
#include "GameStateManager.h"
#include "PlayState.h"

class PickCarState : public GameState
{
public:
	PickCarState(ResourceHolder& resources, GameStateManager& gameStateRef);
	PickCarState(const PickCarState&) = delete;
	PickCarState& operator=(const PickCarState&) = delete;
	~PickCarState();
public:
	virtual void Render(sf::RenderWindow& window);
	virtual void Update(sf::RenderWindow& window, const float dt);
	virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
	ResourceHolder& m_resourceRef;
	GameStateManager& m_gameStateManagerRef;

	sf::Sprite m_Cars;

	Button m_leftButton;
	Button m_rightButton;
	Button m_currentCar;
};

