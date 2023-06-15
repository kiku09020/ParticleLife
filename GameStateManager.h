#pragma once
#include "State.h"

/* Base */
class GameStateMachine;

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
public:
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};

// �|�[�Y
class PauseState : public GameStateBase
{
public:
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};