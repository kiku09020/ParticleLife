#include "GameManager.h"
#include "Input.h"
#include "Color.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameManager manager;

	// ����������
	manager.OnInit();

	// �X�V����
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		manager.OnUpdate();
	}

	// �I������
	manager.OnEnd();
	return 0;
}

//--------------------------------------------------
#pragma region Init


void GameManager::OnInit()
{
	DxLib_Init();								// DxLib������
	SetOutApplicationLogValidFlag(false);		// ���O�o�͂��Ȃ�

	WindowInit();
	DrawingInit();
}

void GameManager::WindowInit()
{
	SetMainWindowText(WINDOW_TITLE);				// �E�B���h�E�^�C�g���w��
	SetBackgroundColor(128, 128, 128);					// �w�i�F�w��

	ChangeWindowMode(true);

	// set icon
}

void GameManager::DrawingInit()
{
	SetDrawScreen(DX_SCREEN_BACK);				// ����ʕ`��
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
	WaitTimer(WAIT_MS);		// �ҋ@
}

//--------------------------------------------------

void GameManager::OnEnd()
{
	DxLib_End();								// DxLib�I������
}

//--------------------------------------------------