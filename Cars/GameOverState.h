#pragma once

#include "GameState.h"
#include "GameStateManager.h"
#include "ResourceHolder.h"
#include "Button.h"

class GameOverState : public GameState
{
public:
    GameOverState();
    GameOverState(const GameOverState&) = delete;
    GameOverState& operator=(const GameOverState&) = delete;
    ~GameOverState();
public:
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    Button m_playAgainButton;
    Button m_quitButton;

};

