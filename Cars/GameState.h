#pragma once

class GameState
{
public:
	GameState(GameState* state);

	GameState* CurrentState();

	virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
private:
	GameState* m_currentState;
};

