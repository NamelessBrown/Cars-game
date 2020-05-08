#include "GameState.h"

GameState::GameState(GameState* state)
	:m_currentState(state)
{
}

GameState* GameState::CurrentState()
{
	return m_currentState;
}
