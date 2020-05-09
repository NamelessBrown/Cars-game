#pragma once

#include <SFML/Graphics.hpp>

/*  
	With the help of <https://www.dreamincode.net/forums/topic/231078-c-tile-engine-from-scratch-part-3/> I was able to make a camera class!
	I had no clue where to start, so I can use this as a base ground for improving it for the future! Thanks to this site!!!
*/

class Camera
{
public:
	Camera(int width, int height, float speed);
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;
	~Camera();
public:
	void Move(int x, int y);
	void MoveCenter(int x, int y);
	void GoTo(int x, int y);
	void GoToCenter(int x, int y);
	void Update(float dt);
	const sf::Vector2i& GetPosition() const;
	sf::Vector2i GetTileOffset(int tileSize);
	sf::IntRect GetTileBounds(int tileSize);
private:
	sf::Vector2f m_position; //Absolute position of camera
	sf::Vector2f m_target; //Where the camera is going to
	sf::Vector2i m_size;

	float m_speed; //camera move speed
};

