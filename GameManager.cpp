#include "GameManager.h"
#include "Input.h"
#include "Color.h"

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
}

void GameManager::WindowInit()
{
	SetMainWindowText(WINDOW_TITLE);				// ウィンドウタイトル指定
	SetBackgroundColor(128, 128, 128);					// 背景色指定

	ChangeWindowMode(true);

	// set icon
}

void GameManager::DrawingInit()
{
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
		DrawCircle(mousePos.x, mousePos.y, 10, Color::White());
	}

	DrawCircle(mousePos.x, mousePos.y, 5, Color::White());

	ScreenFlip();
	WaitTimer(WAIT_MS);		// 待機
}

//--------------------------------------------------

void GameManager::OnEnd()
{
	DxLib_End();								// DxLib終了処理
}

//--------------------------------------------------