#pragma once
#include "DxLib.h"
#include "Extensions/Color.h"

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

	// フルスクリーン時の解像度のモード
	enum FullScrnResolMode
	{
		native	= DX_FSRESOLUTIONMODE_NATIVE,
		desktop = DX_FSRESOLUTIONMODE_DESKTOP,
		maximum = DX_FSRESOLUTIONMODE_MAXIMUM,
	};

	// フルスクリーン時の画面拡大モード
	enum FullScrnScalingMode
	{
		bilinear = DX_FSSCALINGMODE_BILINEAR,
		nearest  = DX_FSSCALINGMODE_NEAREST,
	};

	const TCHAR* WINDOW_TITLE				= "WindowTitle";			// タイトル
	const WindowStyleMode WINDOW_STYLE		= withMaximize;		// ウィンドウスタイル
	const FullScrnResolMode RESOLUTION_MODE = native;			// フルスクリーン解像度モード(違いわからん)
	const FullScrnScalingMode SCALING_MODE	= nearest;			// 画面拡大モード

	const bool ENABLE_CHANGEWINDOWSIZE		= true;				// ウィンドウサイズが変更可能か
	const bool IS_WINDOWMODE				= true;				// ウィンドウモードかどうか
	const bool IS_DISP_MOUSECURSOR			= true;				// マウス表示するかどうか

	const Color bgColor		= Color::GrayWithRGB();				// 背景色
	const int COLORBIT_DEPTH				= 8;				// カラービット

	VECTOR windowSize		= VGet(960.0f, 540.0f, 0.0f);		// サイズ
public:
	Window();

	// ウィンドウサイズの指定
	void SetWindowSize(VECTOR windowSize);

	// Getter
	VECTOR GetWindowSize() { return windowSize; }
};
