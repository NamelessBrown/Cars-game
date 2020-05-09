#pragma once

#include "GameState.h"
#include "ResourceHolder.h"
#include "Tile.h"

class PlayState : public GameState
{
public:
    PlayState(ResourceHolder& resourceManger);
    PlayState(const PlayState&) = delete;
    PlayState& operator=(const PlayState&) = delete;
    ~PlayState();
public:
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    ResourceHolder& m_resourceManger;
    void LoadTiles();
    Tile* m_tile = nullptr;
};

