#include "Player.h"
#include <sstream>

Player::Player(sf::Texture& texture, sf::IntRect& textureRect, const sf::Font& font, sf::Texture& upgradeTexture)
	:m_speed(1.5f), m_health(100), m_points(0), m_upgradeSpeed({900.f, 250.f}, font, upgradeTexture, 50), 
	m_MaxPointsToUpgrade(50), m_MaxHealthToUpgrade(100), m_upgradeHealth({900.f, 450.f}, font, upgradeTexture, 50), m_healthMax(100)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(textureRect);
	m_sprite.setScale(m_sprite.getScale() / 2.f);
	m_sprite.setPosition(480.f, 450.f);

	m_text.setFont(font);
	m_text.setPosition(700.f, 25.f);

	m_upgradeSpeed.SetText("Upgrade speed");
	m_upgradeSpeed.SetScale(6.f);

	m_upgradeHealth.SetText("Upgrade Health");
	m_upgradeHealth.SetScale(6.f);
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

	if (m_upgradeSpeed.IsClicked(sf::Mouse::getPosition(window)) && m_points > m_MaxPointsToUpgrade)
	{
		m_speed += .5f;
		m_MaxPointsToUpgrade += 50;
	}

	if (m_upgradeHealth.IsClicked(sf::Mouse::getPosition(window)) && m_points > m_MaxHealthToUpgrade)
	{
		m_health = m_healthMax;
		m_healthMax = m_MaxHealthToUpgrade;
		m_MaxHealthToUpgrade += 100;
	}


}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
	m_upgradeSpeed.Draw(window);
	m_upgradeHealth.Draw(window);
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

	if (m_sprite.getPosition().x < 300.f)
	{
		m_sprite.setPosition(480.f, 450.f);
	}

	if (m_sprite.getPosition().x > 650.f)
	{
		m_sprite.setPosition(480.f, 450.f);
	}


}
