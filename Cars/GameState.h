#pragma once

#include <SFML/Graphics.hpp>

class GameState
{
public:
    virtual void draw(sf::RenderTarget& target, const float dt) = 0;
    virtual void update(sf::RenderWindow& window, const float dt) = 0;
    virtual void handleInput(sf::RenderWindow& window, sf::Event& events) = 0;
};

