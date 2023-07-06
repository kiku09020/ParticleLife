#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"

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
void Core::OnInit()
{
	mainWindow = new Window();

	SetOutApplicationLogValidFlag(false);		// ログ出力しない
	DxLib_Init();								// DxLib初期化

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