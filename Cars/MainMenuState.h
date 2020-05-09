#pragma once

#include "GameState.h"
#include "Button.h"
#include "ResourceHolder.h"

class MainMenuState : public GameState
{
public:
    MainMenuState(ResourceHolder& textureManger);
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    Button m_startButton;
    Button m_quitButton;

};

