#include "Tile.h"

Tile::Tile(sf::Texture& texture)
{
	m_sprite.setTexture(texture, true);
}

Tile::~Tile()
{
}

void Tile::Draw(float x, float y, sf::RenderWindow& window)
{
	m_sprite.setPosition(x, y);
	window.draw(m_sprite);
}
