#pragma once

#include <stack>
#include "GameState.h"

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow& window);
	GameStateManager(const GameStateManager&) = delete;
	GameStateManager& operator=(const GameStateManager&) = delete;

	~GameStateManager();
	void PushState(GameState* state);
	void PopState();
	void ChangeState(GameState* state);

	GameState* CurrentState();
private:
	sf::RenderWindow& m_window;
	std::stack<GameState*> m_states;
};

