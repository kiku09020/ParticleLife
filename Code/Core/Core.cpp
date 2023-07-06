#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"

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
void Core::OnInit()
{
	mainWindow = new Window();

	SetOutApplicationLogValidFlag(false);		// ���O�o�͂��Ȃ�
	DxLib_Init();								// DxLib������

	SceneController::Init();					// �V�[���̏�����
}


//--------------------------------------------------

void Core::OnUpdate()
{
	ClearDrawScreen();

	SceneController::Update();					// �V�[���̍X�V����

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenFlip();
	WaitTimer(WAIT_MS);
}

//--------------------------------------------------

void Core::OnEnd()
{
	delete mainWindow;

	DxLib_End();								// DxLib�I������
}

//--------------------------------------------------