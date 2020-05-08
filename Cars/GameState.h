#pragma once

#include <SFML/Graphics.hpp>

class GameState
{
public:
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void Update(sf::RenderWindow& window, const float dt) = 0;
    virtual void HandleInput(sf::RenderWindow& window, sf::Event& events) = 0;
};

