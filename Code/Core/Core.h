#pragma once
#include "DxLib.h"
#include "Window/Window.h"

#include "Scene/SceneController.h"

class Core
{
private:
	static Window* mainWindow;

	static const int WAIT_MS			= 10;							// �ҋ@�~���b

	//--------------------------------------------------

public:
	/// <summary>
	/// ���������̏���
	/// </summary>
	static void OnInit();

	/// <summary>
	/// �X�V����
	/// </summary>
	static void OnUpdate();

	/// <summary>
	/// �I�����̏���
	/// </summary>
	static void OnEnd();

	//--------------------------------------------------

	static Window* GetMainWindow() { return mainWindow; }
};