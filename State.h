#pragma once
#include <vector>

// 状態クラス
class BaseState
{
public:
	virtual void OnEnter() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnExit() = 0;
};

//--------------------------------------------------

// 制約
template <typename T>
concept State = std::is_base_of<BaseState, T>::value;

// Stateを管理するクラス
template <State T>
class StateMachine
{
protected:
	T* startState;
	T* currentState;

public:
	template<State U>
	void Init();
	void Update();
	void End();

	// 状態を遷移する
	void StateTransition(T state);

	template <State U>
	void StateTransition();

	// 現在のStateが指定されたStateかどうかを判定する
	bool CheckCurrentState(T state);

	template <State U>
	bool CheckCurrentState();
};

//--------------------------------------------------

template <State T>
template<State U>
void StateMachine<T>::Init()
{
	// 初期状態を設定
	startState = new U();

	currentState = startState;
	currentState->OnEnter();
}

template <State T>
void StateMachine<T>::Update()
{
	currentState->OnUpdate();
}

template<State T>
void StateMachine<T>::End()
{
	delete currentState;
}

//--------------------------------------------------

template <State T>
void StateMachine<T>::StateTransition(T state)
{
	currentState->OnExit();

	delete currentState;
	currentState = new T(state);

	currentState->OnEnter();
}

template <State T>
template <State U>
void StateMachine<T>::StateTransition()
{
	currentState->OnExit();

	delete currentState;
	currentState = new U();

	currentState->OnEnter();
}

//--------------------------------------------------

template <State T>
bool StateMachine<T>::CheckCurrentState(T state)
{
	if ((dynamic_cast<T*>(currentState) != nullptr) && (currentState == &state)){
		return true;
	}

	return false;
}

template <State T>
template <State U>
bool StateMachine<T>::CheckCurrentState()
{
	return dynamic_cast<U*>(currentState) != nullptr;
}