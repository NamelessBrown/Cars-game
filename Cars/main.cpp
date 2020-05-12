// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.h"

int main()
{
	sf::RenderWindow game(sf::VideoMode(1280, 720), "Car bombers", sf::Style::Titlebar | sf::Style::Close);

	Engine e(game);
	e.Run();
}
