#include "Player.h"

Player::Player(sf::Texture& texture, sf::IntRect& textureRect)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureRect);
}

void Player::Update(float dt)
{
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
