#pragma once
#include "DxLib.h"
#include "GameStateManager.h"

class GameManager
{
private:
	const TCHAR* WINDOW_TITLE = "Title";			// �E�B���h�E�^�C�g��

	const int WAIT_MS = 10;							// �ҋ@�~���b

	const VECTOR windowSize = VGet(960.0f, 540.0f, 0.0f);

	const int colorBitDepth = 32;

	GameStateMachine stateMachine;

	//--------------------------------------------------
#pragma region  InitMethods
	/// <summary>
	/// �E�B���h�E�֌W�̏�����
	/// </summary>
	void WindowInit();

	/// <summary>
	/// �`��֌W�̏�����
	/// </summary>
	void DrawingInit();
#pragma endregion

public:

	/// <summary>
	/// ���������̏���
	/// </summary>
	void OnInit();

	/// <summary>
	/// �X�V����
	/// </summary>
	void OnUpdate();

	/// <summary>
	/// �I�����̏���
	/// </summary>
	void OnEnd();
};