#pragma once
#include "DxLib.h"
#include "Color.h"

class Window
{
private:
	// ウィンドウスタイル
	enum WindowStyleMode {
		normal,								// 通常
		withoutTitle,						// タイトルなし
		withoutTitleAndOutline,				// タイトル、アウトラインなし
		withoutOutline,						// アウトラインなし
		none,								// 何もない
		withoutMinimize,					// 最小化、最大化なし
		toolbarWindow,						// ツールバー
		withMaximize,						// 最大化あり
		maximizedSize,						// デフォルトで最大化されたウィンドウサイズにする
		withoutOutlineShadow,				// アウトラインの影なし
		withMaximizeAndWithoutOLShadow,		// 最大化あり、アウトラインの影なし
		withoutCloseAndMinimize,			// 閉じるなし、最小化なし
	};

	const TCHAR* WINDOW_TITLE			= "Title";							// タイトル
	const WindowStyleMode WINDOW_STYLE	= withMaximize;							// ウィンドウスタイル

	const bool ENABLE_CHANGEWINDOWSIZE	= true;								// ウィンドウサイズが変更可能か
	const bool IS_WINDOWMODE			= true;								// ウィンドウモードかどうか

	const Color bgColor	= Color::GrayWithRGB();								// 背景色
	const int COLORBIT_DEPTH			= 8;								// カラービット

	VECTOR windowSize					= VGet(960.0f, 540.0f, 0.0f);		// サイズ
public:
	Window();

	// ウィンドウサイズの指定
	void SetWindowSize(VECTOR windowSize);
};
