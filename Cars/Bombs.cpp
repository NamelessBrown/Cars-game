#include "Bombs.h"
#include <random>

Bombs::Bombs(sf::Texture& texture)
{
	m_sprite.setTexture(texture);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(300.f, 500.f);
	std::uniform_real_distribution<float> speedDistribution(0.5f, 5.5f);

	m_speed = speedDistribution(rng);

	m_sprite.setPosition(distribution(rng), 25.f);
	m_sprite.setScale(m_sprite.getScale() / 4.f);
}

Bombs::~Bombs()
{
}

void Bombs::Update(float dt)
{
	m_sprite.move(0.0f, m_speed * dt);
}

void Bombs::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
