#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button() = default;
	Button(const Button&) = delete;
	Button operator=(const Button&) = delete;

	Button(const sf::Vector2f& position, const std::string& fontFileName, const std::string& textureFile, const int textposition);

	virtual ~Button();

	bool IsClicked(const sf::Sprite& sprite);
	bool IsClicked(const sf::Vector2i& mousePosition);

	void MovePosition(const sf::Vector2f& newPosition);
	void ChangeedFont(const std::string fontFileName);

	void SetTexture(sf::Texture& texture);
	void SetScale(float scaleBy);

	const sf::Sprite& getSprite() const;

	void Draw(sf::RenderWindow& target);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Font m_font;

	bool m_clicked = false;
};

