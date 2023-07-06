#include "Window.h"

Window::Window()
{
	// �E�B���h�E�ݒ�
	SetMainWindowText(WINDOW_TITLE);								// �E�B���h�E�^�C�g���̎w��

	ChangeWindowMode(IS_WINDOWMODE);								// �E�B���h�E���[�h�̎w��
	SetWindowStyleMode((int)WINDOW_STYLE);							// �E�B���h�E�X�^�C���̎w��

	// �E�B���h�E�T�C�Y�ݒ�
	SetGraphMode((int)windowSize.x, (int)windowSize.y, COLORBIT_DEPTH);		// �E�B���h�E�T�C�Y�̎w��
	SetWindowSizeChangeEnableFlag(ENABLE_CHANGEWINDOWSIZE, true);			// �E�B���h�E�T�C�Y��ύX�ł���悤�ɂ��邩���w��
	SetFullScreenResolutionMode(RESOLUTION_MODE);							// �t���X�N���[�����[�h�̉𑜓x�w��
	SetFullScreenScalingMode(SCALING_MODE);

	// �`��ݒ�
	SetBackgroundColor(bgColor.r, bgColor.g, bgColor.b);			// �w�i�F�̎w��

}

void Window::SetWindowSize(VECTOR windowSize)
{
	SetGraphMode((int)windowSize.x, (int)windowSize.y, COLORBIT_DEPTH);
}