#include "GameStateManager.h"
#include "Input.h"
#include "DxLib.h"

using namespace Input;

void MainGameState::OnEnter()
{

}

void MainGameState::OnUpdate()
{
	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {
		stateMachine.StateTransition<PauseState>();
	}
}

void MainGameState::OnExit()
{

}

//--------------------------------------------------

void PauseState::OnEnter()
{
	DrawString(0, 0, "Hello", GetColor(255, 255, 255));
}

void PauseState::OnUpdate()
{
	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {

	}
}

void PauseState::OnExit()
{

}