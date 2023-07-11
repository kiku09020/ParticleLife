#pragma once
#include "DxLib.h"
#include "Window/Window.h"

class Core
{
private:
	static inline Window* mainWindow;							// ���C���E�B���h�E

	static const inline int WAIT_MS			= 10;				// �ҋ@�~���b

	static inline bool ENABLE_LOG			= false;			// ���O�t�@�C�����o�͂��邩
	static inline bool ISRUNNING_ALWAYS		= false;			// �E�B���h�E����A�N�e�B�u�ȏ�Ԃł����s�������邩(�f�t�H�Ffalse)
	static inline bool ENABLE_VSYNC			=  true;			// ScreenFlip���̐���������L���ɂ��邩(�f�t�H�Ftrue)

	//--------------------------------------------------
public:
	// ���������̏��� 
	static int OnInit();

	// �X�V����
	static void OnUpdate();

	// �I�����̏���
	static void OnEnd();

	//--------------------------------------------------
	// �E�B���h�E�̎擾
	static Window* GetMainWindow() { return mainWindow; }
};