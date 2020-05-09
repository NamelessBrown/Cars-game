#pragma once

#include "GameState.h"
#include "Button.h"
#include "ResourceHolder.h"
#include "GameStateManager.h"

class MainMenuState : public GameState
{
public:
    MainMenuState(ResourceHolder& textureManger, GameStateManager& states);
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    GameStateManager& m_stateManagerRef;
    Button m_startButton;
    Button m_quitButton;

};

