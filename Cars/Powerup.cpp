#include "Powerup.h"
#include <random>

Powerup::Powerup(sf::Texture& texture)
	:m_speed(1.5f)
{
	m_sprite.setTexture(texture);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(300.f, 500.f);
	std::uniform_real_distribution<float> speedDistribution(.5f, 1.f);

	m_sprite.setPosition(distribution(rng), 25.f);
	m_sprite.setScale(m_sprite.getScale() / 4.f);

	m_speed = speedDistribution(rng);

}

Powerup::~Powerup()
{
}

void Powerup::Update(float dt)
{
	m_sprite.move(0.0f, m_speed * dt);
}

void Powerup::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
