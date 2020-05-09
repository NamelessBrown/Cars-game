#include "Camera.h"

Camera::Camera(int width, int height, float speed)
	:m_speed(speed), m_size{width, height}
{
}

Camera::~Camera()
{
}

void Camera::Move(int x, int y)
{
	m_position.x = (float)x;
	m_position.y = (float)y;
	m_target.x = (float)x;
	m_target.y = (float)y;
}

void Camera::MoveCenter(int x, int y)
{
	x -= (m_size.x / 2);
	y -= (m_size.y / 2);

	Move(x, y);
}

void Camera::GoTo(int x, int y)
{
	m_target.x = (float)x;
	m_target.y = (float)y;
}

void Camera::GoToCenter(int x, int y)
{
	x -= (m_size.x / 2);
	y -= (m_size.y / 2);

	GoTo(x, y);
}

void Camera::Update(float dt)
{
	float targetX, targetY, distance;
	float velocityX, velocityY, velocity;

	//target positions
	targetX = (float)(m_target.x - m_position.x);
	targetY = (float)(m_target.y - m_position.y);

	//If the position is close the target
	if ((targetX * targetX + targetY * targetY) <= 1)
	{
		m_position.x = m_target.x;
		m_position.y = m_target.y;
	}
	else
	{
		//distance formula
		distance = sqrt((targetX * targetX + targetY * targetY));

		//veclocities
		velocity = (distance * m_speed) / dt;

		if (velocity <= 1.f) //can't be less than zero
		{
			velocity = 1.f;
		}

		velocityX = targetX * (velocity / distance);
		velocityY = targetY * (velocity / distance);

		m_position.x += velocityX;
		m_position.y += velocityY;
	}

}

const sf::Vector2i Camera::GetPosition() const
{
	return sf::Vector2i((int)m_position.x, (int)m_position.y);
}

sf::Vector2i Camera::GetTileOffset(int tileSize)
{
	return sf::Vector2i((int)(m_position.x) % tileSize, (int)(m_position.y) % tileSize);
}

sf::IntRect Camera::GetTileBounds(int tileSize)
{
	int x = (int)(m_position.x / tileSize);
	int y = (int)(m_position.y / tileSize);

	//If it isn't divisible by tileSize
	int width = (int)(m_size.x / tileSize + 2);
	int height = (int)(m_size.y / tileSize + 2);

	if (x % tileSize != 0)
		width++;

	if (y % tileSize != 0)
		height++;

	return sf::IntRect(x, y, width, height);
}
