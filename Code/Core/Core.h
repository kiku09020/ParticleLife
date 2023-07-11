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

	static const inline int WAIT_MS			= 10;							// 待機ミリ秒

	//--------------------------------------------------

public:
	/// <summary>
	/// 初期化時の処理
	/// </summary>
	static int OnInit();

	/// <summary>
	/// 更新処理
	/// </summary>
	static void OnUpdate();

	/// <summary>
	/// 終了時の処理
	/// </summary>
	static void OnEnd();

	//--------------------------------------------------

	static Window* GetMainWindow() { return mainWindow; }
};