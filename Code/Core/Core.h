#pragma once
#include "DxLib.h"
#include "Window/Window.h"

#include "Scene/SceneController.h"
#include "UI/UIManager.h"

class Core
{
private:
	static inline UIManager uiManager;
	static inline Window* mainWindow;

	static const inline int WAIT_MS			= 10;							// �ҋ@�~���b

	//--------------------------------------------------

public:
	/// <summary>
	/// ���������̏���
	/// </summary>
	static int OnInit();

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