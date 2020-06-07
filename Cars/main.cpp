// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.h"

int main()
{
	Engine::GetInstance()->Init(100, 100, 1280, 720, false, "Cars");

	Engine::GetInstance()->Run();

	Engine::GetInstance()->Quit();
}
