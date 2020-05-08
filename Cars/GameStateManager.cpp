#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
	while (!m_states.empty())
	{
		PopState();
	}
}

void GameStateManager::PushState(GameState* state)
{
	m_states.push(state);
}

void GameStateManager::PopState()
{
	delete m_states.top();
	m_states.pop();
}

void GameStateManager::ChangeState(GameState* state)
{
	if (!m_states.empty())
	{
		PopState();
	}

	PushState(state);
}

GameState* GameStateManager::CurrentState()
{
	if(m_states.empty())
	{
		return nullptr;
	}

	return m_states.top();
}
