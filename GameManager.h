#pragma once
#include "DxLib.h"

class GameManager
{
	const TCHAR* WINDOW_TITLE = "Title";			// �E�B���h�E�^�C�g��

	const int WAIT_MS = 10;							// �ҋ@�~���b

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