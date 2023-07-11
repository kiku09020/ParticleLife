#pragma once
#include "DxLib.h"
#include "Extensions/Color.h"

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

	// �t���X�N���[�����̉𑜓x�̃��[�h
	enum FullScrnResolMode
	{
		native	= DX_FSRESOLUTIONMODE_NATIVE,
		desktop = DX_FSRESOLUTIONMODE_DESKTOP,
		maximum = DX_FSRESOLUTIONMODE_MAXIMUM,
	};

	// �t���X�N���[�����̉�ʊg�僂�[�h
	enum FullScrnScalingMode
	{
		bilinear = DX_FSSCALINGMODE_BILINEAR,
		nearest  = DX_FSSCALINGMODE_NEAREST,
	};

	const TCHAR* WINDOW_TITLE				= "WindowTitle";			// �^�C�g��
	const WindowStyleMode WINDOW_STYLE		= withMaximize;		// �E�B���h�E�X�^�C��
	const FullScrnResolMode RESOLUTION_MODE = native;			// �t���X�N���[���𑜓x���[�h(�Ⴂ�킩���)
	const FullScrnScalingMode SCALING_MODE	= nearest;			// ��ʊg�僂�[�h

	const bool ENABLE_CHANGEWINDOWSIZE		= true;				// �E�B���h�E�T�C�Y���ύX�\��
	const bool IS_WINDOWMODE				= true;				// �E�B���h�E���[�h���ǂ���
	const bool IS_DISP_MOUSECURSOR			= true;				// �}�E�X�\�����邩�ǂ���

	const Color bgColor		= Color::GrayWithRGB();				// �w�i�F
	const int COLORBIT_DEPTH				= 8;				// �J���[�r�b�g

	VECTOR windowSize		= VGet(960.0f, 540.0f, 0.0f);		// �T�C�Y
public:
	Window();

	// �E�B���h�E�T�C�Y�̎w��
	void SetWindowSize(VECTOR windowSize);

	// Getter
	VECTOR GetWindowSize() { return windowSize; }
};
