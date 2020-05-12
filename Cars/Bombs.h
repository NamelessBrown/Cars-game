#pragma once

#include <SFML/Graphics.hpp>

class Bombs
{
public:
	Bombs(sf::Texture& texture);
	~Bombs();

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Sprite m_sprite;

	float m_speed;
};

