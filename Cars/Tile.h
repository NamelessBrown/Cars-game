#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(sf::Texture& texture);
	~Tile();

	void Draw(float x, float y, sf::RenderWindow& window);
private:
	sf::Sprite m_sprite;
};

