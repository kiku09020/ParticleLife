#pragma once
#include "State.h"

/* Base */
class GameStateMachine;

// ゲーム状態の基底クラス
class GameStateBase : public BaseState
{

};

// ゲームの状態管理クラス
class GameStateMachine : public StateMachine<GameStateBase>
{
	
};

//--------------------------------------------------
/* States */

// メイン状態
class MainGameState : public GameStateBase
{
public:
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};

// ポーズ
class PauseState : public GameStateBase
{
public:
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};