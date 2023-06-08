#pragma once
#include "DxLib.h"

class GameManager
{
	const TCHAR* WINDOW_TITLE = "Title";			// ウィンドウタイトル

	const int WAIT_MS = 10;							// 待機ミリ秒

	//--------------------------------------------------
#pragma region  InitMethods
	/// <summary>
	/// ウィンドウ関係の初期化
	/// </summary>
	void WindowInit();

	/// <summary>
	/// 描画関係の初期化
	/// </summary>
	void DrawingInit();
#pragma endregion

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