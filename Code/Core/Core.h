#pragma once
#include "DxLib.h"
#include "Window/Window.h"

#include "Scene/SceneController.h"

class Core
{
private:
	Window* mainWindow;

	const int WAIT_MS			= 10;							// 待機ミリ秒

	//--------------------------------------------------

public:

	/// <summary>
	/// 初期化時の処理
	/// </summary>
	void OnInit();

	/// <summary>
	/// 更新処理
	/// </summary>
	void OnUpdate();

	/// <summary>
	/// 終了時の処理
	/// </summary>
	void OnEnd();
};