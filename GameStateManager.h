#pragma once
#include "State.h"

/* Base */

// �Q�[����Ԃ̊��N���X
class GameStateBase : public BaseState
{

};

// �Q�[���̏�ԊǗ��N���X
class GameStateMachine : public StateMachine<GameStateBase>
{
	
};

//--------------------------------------------------
/* States */

// ���C�����
class MainGameState : public GameStateBase
{
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};

// �|�[�Y
class PauseState : public GameStateBase
{
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};