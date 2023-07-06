#include "Window.h"

Window::Window()
{
	// ウィンドウ設定
	SetMainWindowText(WINDOW_TITLE);								// ウィンドウタイトルの指定

	ChangeWindowMode(IS_WINDOWMODE);								// ウィンドウモードの指定
	SetWindowStyleMode((int)WINDOW_STYLE);							// ウィンドウスタイルの指定

	// ウィンドウサイズ設定
	SetGraphMode((int)windowSize.x, (int)windowSize.y, COLORBIT_DEPTH);		// ウィンドウサイズの指定
	SetWindowSizeChangeEnableFlag(ENABLE_CHANGEWINDOWSIZE, true);			// ウィンドウサイズを変更できるようにするかを指定
	SetFullScreenResolutionMode(RESOLUTION_MODE);							// フルスクリーンモードの解像度指定
	SetFullScreenScalingMode(SCALING_MODE);

	// 描画設定
	SetBackgroundColor(bgColor.r, bgColor.g, bgColor.b);			// 背景色の指定

}

void Window::SetWindowSize(VECTOR windowSize)
{
	SetGraphMode((int)windowSize.x, (int)windowSize.y, COLORBIT_DEPTH);
}