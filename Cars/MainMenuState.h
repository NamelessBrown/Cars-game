#pragma once

#include "GameState.h"
#include "Button.h"
#include "ResourceHolder.h"
#include "GameStateManager.h"
#include "PlayState.h"

class MainMenuState : public GameState
{
public:
    MainMenuState(ResourceHolder& textureManger, GameStateManager& states);
    MainMenuState(const MainMenuState&) = delete;
    MainMenuState& operator=(const MainMenuState&) = delete;
    ~MainMenuState();
public:
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    GameStateManager& m_stateManagerRef;
    ResourceHolder& m_resourceManagerRef;

    sf::Sprite m_background;

    Button m_startButton;
    Button m_quitButton;

};

