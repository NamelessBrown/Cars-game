#pragma once

#include "GameState.h"
#include "ResourceHolder.h"
#include "Player.h"

class PlayState : public GameState
{
public:
    PlayState(ResourceHolder& resourceManger, sf::IntRect& textureRect);
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
    sf::Sprite m_background;

    Player m_player;

    double m_backgroundScroll;
    double m_backgroundScrollSpeed;

};

