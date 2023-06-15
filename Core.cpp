#include "Core.h"
#include "Input.h"
#include "Color.h"

using namespace Input;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Core core;

	// 初期化処理
	core.OnInit();

	// 更新処理
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		core.OnUpdate();
	}

	// 終了処理
	core.OnEnd();
	return 0;
}

//--------------------------------------------------
#pragma region Init


void Core::OnInit()
{
	DxLib_Init();								// DxLib初期化
	SetOutApplicationLogValidFlag(false);		// ログ出力しない

	WindowInit();
	DrawingInit();
}

void Core::WindowInit()
{
	SetMainWindowText(WINDOW_TITLE);			// ウィンドウタイトル指定
	ChangeWindowMode(true);						// ウィンドウモードに指定

	SetGraphMode((int)windowSize.x, (int)windowSize.y, colorBitDepth);		// ウィンドウサイズ、カラービットの指定

	// ウィンドウアイコン指定

}

void Core::DrawingInit()
{
	SetBackgroundColor(128, 128, 128);			// 背景色指定
	SetDrawScreen(DX_SCREEN_BACK);				// 裏画面描画
}
#pragma endregion

//--------------------------------------------------

void Core::OnUpdate()
{
	ClearDrawScreen();

	VECTOR mousePos = Mouse::GetMousePosition();

	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {
		OnEnd();
	}

	if (Mouse::GetMouseButton(MOUSE_INPUT_LEFT)) {
		DrawCircleAA(mousePos.x, mousePos.y, 10, 32, Color::White());
	}

	DrawCircleAA(mousePos.x, mousePos.y, 5,32, Color::White());

	ScreenFlip();
	WaitTimer(WAIT_MS);		// 待機
}

//--------------------------------------------------

void Core::OnEnd()
{
	DxLib_End();								// DxLib終了処理
}

//--------------------------------------------------