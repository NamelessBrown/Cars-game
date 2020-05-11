#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Texture& texture, sf::IntRect& textureRect);

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	void Movement(float dt);
private:
	sf::Sprite m_sprite;

	float m_speed;
};

