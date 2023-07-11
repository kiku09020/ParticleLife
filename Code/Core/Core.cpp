#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"

using namespace Input;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// DxLib������
	if (Core::OnInit() == -1) { return -1; }

	// �X�V����
	while (ProcessMessage() == 0) {
		Mouse::Update();
		Keyboard::Update();
		Core::OnUpdate();
	}

	// �I������
	Core::OnEnd();
	return 0;
}

//--------------------------------------------------
int Core::OnInit()
{
	mainWindow = new Window();
	if (DxLib_Init() == -1) { return -1; }


	SetOutApplicationLogValidFlag(false);		// ���O�o�͂��Ȃ�


	SceneController::Init();					// �V�[���̏�����
	UIManager::Init();
}


//--------------------------------------------------

void Core::OnUpdate()
{
	ClearDrawScreen();

	UIManager::Update();
	SceneController::Update();					// �V�[���̍X�V����

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenFlip();
	WaitTimer(WAIT_MS);
}

//--------------------------------------------------

void Core::OnEnd()
{
	delete mainWindow;

	UIManager::OnEnd();
	DxLib_End();								// DxLib�I������
}

//--------------------------------------------------