#pragma once

#include "GameState.h"

class MainMenuState : public GameState
{
public:
    MainMenuState();
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
};

