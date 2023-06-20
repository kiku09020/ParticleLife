#pragma once
#include "DxLib.h"
#include "Color.h"

class Window
{
private:
	// �E�B���h�E�X�^�C��
	enum WindowStyleMode {
		normal,								// �ʏ�
		withoutTitle,						// �^�C�g���Ȃ�
		withoutTitleAndOutline,				// �^�C�g���A�A�E�g���C���Ȃ�
		withoutOutline,						// �A�E�g���C���Ȃ�
		none,								// �����Ȃ�
		withoutMinimize,					// �ŏ����A�ő剻�Ȃ�
		toolbarWindow,						// �c�[���o�[
		withMaximize,						// �ő剻����
		maximizedSize,						// �f�t�H���g�ōő剻���ꂽ�E�B���h�E�T�C�Y�ɂ���
		withoutOutlineShadow,				// �A�E�g���C���̉e�Ȃ�
		withMaximizeAndWithoutOLShadow,		// �ő剻����A�A�E�g���C���̉e�Ȃ�
		withoutCloseAndMinimize,			// ����Ȃ��A�ŏ����Ȃ�
	};

	const TCHAR* WINDOW_TITLE			= "Title";							// �^�C�g��
	const WindowStyleMode WINDOW_STYLE	= withMaximize;							// �E�B���h�E�X�^�C��

	const bool ENABLE_CHANGEWINDOWSIZE	= true;								// �E�B���h�E�T�C�Y���ύX�\��
	const bool IS_WINDOWMODE			= true;								// �E�B���h�E���[�h���ǂ���

	const Color bgColor	= Color::GrayWithRGB();								// �w�i�F
	const int COLORBIT_DEPTH			= 8;								// �J���[�r�b�g

	VECTOR windowSize					= VGet(960.0f, 540.0f, 0.0f);		// �T�C�Y
public:
	Window();

	// �E�B���h�E�T�C�Y�̎w��
	void SetWindowSize(VECTOR windowSize);
};
