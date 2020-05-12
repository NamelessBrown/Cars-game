#include "Player.h"
#include <sstream>

Player::Player(sf::Texture& texture, sf::IntRect& textureRect, const sf::Font& font)
	:m_speed(1.5f), m_health(100), m_points(0), m_upgradeSpeed({800.f, 25.f}, font, texture, 12)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureRect);
	m_sprite.setScale(m_sprite.getScale() / 2.f);
	m_sprite.setPosition(480.f, 450.f);

	m_text.setFont(font);
	m_text.setPosition(700.f, 25.f);

	m_upgradeSpeed.SetText("Upgrade speed");
}

bool Player::isDead()
{
	return m_health <= 0;
}

void Player::Update(sf::RenderWindow& window, float dt)
{
	Movement(dt);

	std::stringstream ss;
	ss << "Health: " << m_health << " Speed: " << m_speed << '\n';
	ss << "Points: " << m_points;
	m_text.setString(ss.str());

	if (m_upgradeSpeed.IsClicked(sf::Mouse::getPosition(window)))
	{
		m_speed += 1.5f;
	}

}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
	m_upgradeSpeed.Draw(window);
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
