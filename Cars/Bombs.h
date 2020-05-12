#pragma once

#include <SFML/Graphics.hpp>

class Bombs
{
public:
	Bombs(sf::Texture& texture);
	~Bombs();

	const int& GetDamage() const { return m_damage; }
	const sf::Sprite& GetSprite() const { return m_sprite; }
	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Sprite m_sprite;

	float m_speed;
	int m_damage;
};

