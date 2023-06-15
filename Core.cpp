#include "Core.h"
#include "Input.h"
#include "Color.h"

using namespace Input;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Core core;

	// ����������
	core.OnInit();

	// �X�V����
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		core.OnUpdate();
	}

	// �I������
	core.OnEnd();
	return 0;
}

//--------------------------------------------------
#pragma region Init


void Core::OnInit()
{
	DxLib_Init();								// DxLib������
	SetOutApplicationLogValidFlag(false);		// ���O�o�͂��Ȃ�

	WindowInit();
	DrawingInit();
}

void Core::WindowInit()
{
	SetMainWindowText(WINDOW_TITLE);			// �E�B���h�E�^�C�g���w��
	ChangeWindowMode(true);						// �E�B���h�E���[�h�Ɏw��

	SetGraphMode((int)windowSize.x, (int)windowSize.y, colorBitDepth);		// �E�B���h�E�T�C�Y�A�J���[�r�b�g�̎w��

	// �E�B���h�E�A�C�R���w��

}

void Core::DrawingInit()
{
	SetBackgroundColor(128, 128, 128);			// �w�i�F�w��
	SetDrawScreen(DX_SCREEN_BACK);				// ����ʕ`��
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
	WaitTimer(WAIT_MS);		// �ҋ@
}

//--------------------------------------------------

void Core::OnEnd()
{
	DxLib_End();								// DxLib�I������
}

//--------------------------------------------------