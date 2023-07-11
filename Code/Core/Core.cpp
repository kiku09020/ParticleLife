#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"
#include "Scene/SceneController.h"

using namespace Input;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// DxLib初期化
	if (Core::OnInit() == -1) { return -1; }

	// 更新処理
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		Core::OnUpdate();
	}

	// 終了処理
	Core::OnEnd();
	return 0;
}

//--------------------------------------------------

int Core::OnInit()
{
	mainWindow = new Window();					// ウィンドウ、描画系のセットアップ

	SetAlwaysRunFlag(ISRUNNING_ALWAYS);			// 常時処理するか
	SetOutApplicationLogValidFlag(ENABLE_LOG);	// ログ出力
	SetWaitVSyncFlag(ENABLE_VSYNC);				// Vsync

	if (DxLib_Init() == -1) { return -1; }		// DxLib初期化(エラー時に終了)

	SceneController::Init();					// シーンの初期化
}

//--------------------------------------------------

void Core::OnUpdate()
{
	ClearDrawScreen();

	SceneController::Update();					// シーンの更新処理

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenFlip();
	WaitTimer(WAIT_MS);
}

//--------------------------------------------------

void Core::OnEnd()
{
	delete mainWindow;

	DxLib_End();								// DxLib終了処理
}

//--------------------------------------------------