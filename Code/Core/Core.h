#pragma once
#include "DxLib.h"
#include "Window/Window.h"

#include "Scene/SceneController.h"

class Core
{
private:
	Window* mainWindow;

	const int WAIT_MS			= 10;							// �ҋ@�~���b

	//--------------------------------------------------

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