#include "GameManager.h"
#include "Input.h"
#include "Color.h"

using namespace Input;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameManager manager;

	// 初期化処理
	manager.OnInit();

	// 更新処理
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		manager.OnUpdate();
	}

	// 終了処理
	manager.OnEnd();
	return 0;
}

//--------------------------------------------------
#pragma region Init


void GameManager::OnInit()
{
	DxLib_Init();								// DxLib初期化
	SetOutApplicationLogValidFlag(false);		// ログ出力しない

	WindowInit();
	DrawingInit();

	stateMachine.Init<MainGameState>();
}

void GameManager::WindowInit()
{
	SetMainWindowText(WINDOW_TITLE);			// ウィンドウタイトル指定

	SetGraphMode((int)windowSize.x, (int)windowSize.y, colorBitDepth);
	ChangeWindowMode(true);

	// set icon
}

void GameManager::DrawingInit()
{
	SetBackgroundColor(128, 128, 128);			// 背景色指定
	SetDrawScreen(DX_SCREEN_BACK);				// 裏画面描画
}
#pragma endregion

//--------------------------------------------------

void GameManager::OnUpdate()
{
	ClearDrawScreen();

	VECTOR mousePos = Mouse::GetMousePosition();

	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {
		OnEnd();
	}

	if (Mouse::GetMouseButton(MOUSE_INPUT_LEFT)) {
		DrawCircleAA(mousePos.x, mousePos.y, 10, 32, Color::White());
	}

	stateMachine.Update();

	DrawCircleAA(mousePos.x, mousePos.y, 5,32, Color::White());

	ScreenFlip();
	WaitTimer(WAIT_MS);		// 待機
}

//--------------------------------------------------

void GameManager::OnEnd()
{
	DxLib_End();								// DxLib終了処理
}

//--------------------------------------------------