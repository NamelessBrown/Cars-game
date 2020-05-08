// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.h"

int main()
{
	sf::RenderWindow test(sf::VideoMode(600, 600), "Test", sf::Style::Titlebar | sf::Style::Close);

	Engine e(test);
	e.Run();
}
