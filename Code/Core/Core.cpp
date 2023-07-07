#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"
#include "UI/UIManager.h"

using namespace Input;

Window* Core::mainWindow;
const int Core::WAIT_MS;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ����������
	Core::OnInit();

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
void Core::OnInit()
{
	mainWindow = new Window();

	SetOutApplicationLogValidFlag(false);		// ���O�o�͂��Ȃ�
	DxLib_Init();								// DxLib������

	UIManager::Init();
	SceneController::Init();					// �V�[���̏�����
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