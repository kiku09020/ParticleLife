#include "Core.h"
#include "Input/Input.h"
#include "Extensions/Color.h"
#include "Scene/SceneController.h"

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
	mainWindow = new Window();					// �E�B���h�E�A�`��n�̃Z�b�g�A�b�v

	SetAlwaysRunFlag(ISRUNNING_ALWAYS);			// �펞�������邩
	SetOutApplicationLogValidFlag(ENABLE_LOG);	// ���O�o��
	SetWaitVSyncFlag(ENABLE_VSYNC);				// Vsync

	if (DxLib_Init() == -1) { return -1; }		// DxLib������(�G���[���ɏI��)

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