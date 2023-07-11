#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"

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
	mainWindow = new Window();
	if (DxLib_Init() == -1) { return -1; }


	SetOutApplicationLogValidFlag(false);		// ログ出力しない


	SceneController::Init();					// シーンの初期化
	UIManager::Init();
}


//--------------------------------------------------

void Core::OnUpdate()
{
	ClearDrawScreen();

	UIManager::Update();
	SceneController::Update();					// シーンの更新処理

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenFlip();
	WaitTimer(WAIT_MS);
}

//--------------------------------------------------

void Core::OnEnd()
{
	delete mainWindow;

	UIManager::OnEnd();
	DxLib_End();								// DxLib終了処理
}

//--------------------------------------------------