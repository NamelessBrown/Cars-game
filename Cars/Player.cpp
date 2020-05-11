#include "Player.h"

Player::Player(sf::Texture& texture, sf::IntRect& textureRect)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureRect);
	m_sprite.setScale(m_sprite.getScale() / 2.f);
	m_sprite.setPosition(480.f, 450.f);
}

void Player::Update(float dt)
{
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
