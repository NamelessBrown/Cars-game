#pragma once

#include <vector>
#include "GameState.h"
#include "ResourceHolder.h"
#include "Player.h"
#include "Button.h"
#include "GameStateManager.h"
#include "Bombs.h"

class PlayState : public GameState
{
public:
    PlayState(ResourceHolder& resourceManger, sf::IntRect& textureRect, GameStateManager& gameStateManager);
    PlayState(const PlayState&) = delete;
    PlayState& operator=(const PlayState&) = delete;
    ~PlayState();
public:
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);

    void MoveBackground(const float dt);
private:
    ResourceHolder& m_resourceManger;
    GameStateManager& m_gameStateManager;
    sf::Sprite m_background;

    Button m_upgradeButton;
    Player m_player;
    std::vector<Bombs> m_bombs;

    double m_backgroundScroll;
    double m_backgroundScrollSpeed;

};

