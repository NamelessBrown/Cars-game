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
	void GainPowerup(float speeed) { m_speed += speeed; }
	void LoseHealth(int neg) { m_health -= neg; }
	void Update(sf::RenderWindow& window, float dt);
	void Render(sf::RenderWindow& window);
private:
	void Movement(float dt);
private:
	sf::Sprite m_sprite;
	sf::Text m_text;

	Button m_upgradeSpeed;
	Button m_upgradeHealth;

	int m_health;
	int m_healthMax; //Max health for the player
	int m_MaxHealthToUpgrade; //This is use for upgrading the healthMax var
	float m_speed;
	int m_points;
	int m_MaxPointsToUpgrade;
};

