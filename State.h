#pragma once
#include <vector>

// ��ԃN���X
class BaseState
{
public:
	virtual void OnEnter() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnExit() = 0;
};

//--------------------------------------------------

// ����
template <typename T>
concept State = std::is_base_of<BaseState, T>::value;

// State���Ǘ�����N���X
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

	// ��Ԃ�J�ڂ���
	void StateTransition(T state);

	template <State U>
	void StateTransition();

	// ���݂�State���w�肳�ꂽState���ǂ����𔻒肷��
	bool CheckCurrentState(T state);

	template <State U>
	bool CheckCurrentState();
};

//--------------------------------------------------

template <State T>
template<State U>
void StateMachine<T>::Init()
{
	// ������Ԃ�ݒ�
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