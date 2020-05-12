#include "Bombs.h"

Bombs::Bombs(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(300.f, 50.f);
	m_sprite.setScale(m_sprite.getScale() / 4.f);
}

Bombs::~Bombs()
{
}

void Bombs::Update(float dt)
{
}

void Bombs::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
