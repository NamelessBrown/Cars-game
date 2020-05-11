#include "Player.h"

Player::Player(sf::Texture& texture, sf::IntRect& textureRect)
	:m_speed(1.5f)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureRect);
	m_sprite.setScale(m_sprite.getScale() / 2.f);
	m_sprite.setPosition(480.f, 450.f);
}

void Player::Update(float dt)
{
	Movement(dt);
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::Movement(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		m_sprite.move(m_speed * dt, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		m_sprite.move(-(m_speed * dt), 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		m_sprite.move(0.f, -(m_speed * dt));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		m_sprite.move(0.f, m_speed * dt);
	}
}
