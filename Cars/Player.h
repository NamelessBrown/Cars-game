#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Player
{
public:
	Player(sf::Texture& texture, sf::IntRect& textureRect, const sf::Font& font, sf::Texture& upgradeTexture);

	bool isDead();
	const sf::Sprite& GetSprite() const { return m_sprite; }
	void GainPoints(int p) { m_points += p; }
	void LoseHealth(int neg) { m_health -= neg; }
	void Update(sf::RenderWindow& window, float dt);
	void Render(sf::RenderWindow& window);
private:
	void Movement(float dt);
private:
	sf::Sprite m_sprite;
	sf::Text m_text;

	Button m_upgradeSpeed;

	int m_health;
	float m_speed;
	int m_points;
	int m_MaxPointsToUpgrade;
};

