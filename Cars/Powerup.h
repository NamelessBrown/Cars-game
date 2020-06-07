#pragma once

#include <SFML/Graphics.hpp>

class Powerup
{
public:
	Powerup(sf::Texture& texture);
	~Powerup();

	const float GetSpeed() const { return m_speed; }
	const sf::Sprite& GetSprite() const { return m_sprite; }
	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Sprite m_sprite;

	float m_speed;
};

