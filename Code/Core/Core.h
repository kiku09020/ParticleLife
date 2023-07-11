#pragma once
#include "DxLib.h"
#include "Window/Window.h"

class Core
{
private:
	static inline Window* mainWindow;							// メインウィンドウ

	static const inline int WAIT_MS			= 10;				// 待機ミリ秒

	static inline bool ENABLE_LOG			= false;			// ログファイルを出力するか
	static inline bool ISRUNNING_ALWAYS		= false;			// ウィンドウが非アクティブな状態でも実行し続けるか(デフォ：false)
	static inline bool ENABLE_VSYNC			=  true;			// ScreenFlip時の垂直同期を有効にするか(デフォ：true)

	//--------------------------------------------------
public:
	// 初期化時の処理 
	static int OnInit();

	// 更新処理
	static void OnUpdate();

	// 終了時の処理
	static void OnEnd();

	//--------------------------------------------------
	// ウィンドウの取得
	static Window* GetMainWindow() { return mainWindow; }
};