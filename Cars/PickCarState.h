#pragma once

#include "GameState.h"
#include "ResourceHolder.h"
#include "Button.h"
#include "GameStateManager.h"
#include "PlayState.h"

class PickCarState : public GameState
{
public:
	PickCarState();
	PickCarState(const PickCarState&) = delete;
	PickCarState& operator=(const PickCarState&) = delete;
	~PickCarState();
public:
	virtual void Render(sf::RenderWindow& window);
	virtual void Update(sf::RenderWindow& window, const float dt);
	virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
	sf::Sprite m_Cars;
	sf::IntRect m_textureRect;

	Button m_leftButton;
	Button m_rightButton;
	Button m_currentCar;

	/* for the car pictures (97 is the defualt value of the picture)
	int m_width = 98;
	int m_height = 98;
	int m_top = 0; */
};

