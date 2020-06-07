#pragma once

#include <vector>
#include "GameState.h"
#include "ResourceHolder.h"
#include "Player.h"
#include "Button.h"
#include "GameStateManager.h"
#include "Bombs.h"
#include "Powerup.h"

class PlayState : public GameState
{
public:
    PlayState(sf::IntRect& textureRect);
    PlayState(const PlayState&) = delete;
    PlayState& operator=(const PlayState&) = delete;
    ~PlayState();
public:
    virtual void Render(sf::RenderWindow& window);
    virtual void Update(sf::RenderWindow& window, const float dt);
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events);
private:
    void MoveBackground(const float dt);
    void SpawnBomb(int amount);
    void SpawnPowerup(int amount);
    void Collision();
private:
    sf::Sprite m_background;

    Player m_player;
    std::vector<Bombs> m_bombs;
    std::vector<Powerup> m_powerups;

    double m_backgroundScroll;
    double m_backgroundScrollSpeed;

};

