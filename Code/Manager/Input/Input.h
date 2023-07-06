#pragma once
#include "DxLib.h"
#include <array>
#include <iostream>

//--------------------------------------------------

namespace Input {
	class Mouse
	{
		static const int BUFFER_SIZE = 3;							// ���͂̃o�b�t�@�T�C�Y

		static std::array<char, BUFFER_SIZE> inputBuffer;			// ���̓o�b�t�@
		static std::array<char, BUFFER_SIZE> inputBuffer_prev;		// �O�t���[���̓��̓o�b�t�@

		static std::array<bool, BUFFER_SIZE> isKeyDown;				// ���͂��ꂽ�u��
		static std::array<bool, BUFFER_SIZE> isKeyUp;				// ���͂������ꂽ�u��

		//--------------------------------------------------
		// *MousePosition
		static const VECTOR START_MOUSE_POSITION;					// �ŏ��̃}�E�X�|�C���^�̈ʒu
		static VECTOR prevMousePosition;							// �O�t���[���̃}�E�X�|�C���^�̈ʒu
		static VECTOR mousePosition;								// �}�E�X�|�C���^�̈ʒu

		// *MouseWheel
		static bool isWheelForward;									// �}�E�X�z�C�[�����O�����ɃX�N���[�����ꂽ��
		static bool isWheelBack;									// �}�E�X�z�C�[�����������ɃX�N���[�����ꂽ��

		// �}�E�X�{�^���̃R�[�h���擾
		static int CheckMouseButtonCode(int keyCode);
		static void SetMousePosition();								// �}�E�X�|�C���^�̈ʒu���Z�b�g����
		static void SetMouseWheelState();							// �}�E�X�z�C�[���̏�Ԃ��擾����
		//--------------------------------------------------

	public:
		static void Init();
		static void Update();

		// Getter
		static bool GetMouseButton(int button);
		static bool GetMouseButtonDown(int button);
		static bool GetMouseButtonUp(int button);

		static constexpr int GetMouseBufferSize()	{ return BUFFER_SIZE; }
		static VECTOR GetMousePosition()			{ return mousePosition; }		// �}�E�X�|�C���^�̈ʒu���擾����

		// �ړ��ʂ��擾����
		static VECTOR GetMouseMoveDelta();

		static bool GetIsWheelForward()				{ return isWheelForward; }
		static bool GetIsWheelBack()				{ return isWheelBack; }
	};

	static class Keyboard
	{
		static const int BUFFER_SIZE = 256;							// ���͂̃o�b�t�@�T�C�Y

		static std::array<char, BUFFER_SIZE> inputBuffer;			// ���̓o�b�t�@
		static std::array<char, BUFFER_SIZE> inputBuffer_prev;		// �O�t���[���̓��̓o�b�t�@

		static std::array<bool, BUFFER_SIZE> isKeyDown;				// ���͂��ꂽ�u��
		static std::array<bool, BUFFER_SIZE> isKeyUp;				// ���͂������ꂽ�u��

	public:
		static void Init();
		static void Update();

		static bool GetKey(int key);
		static bool GetKeyDown(int key);
		static bool GetKeyUp(int key);

		static constexpr int GetKeyBufferSize() { return BUFFER_SIZE; }
	};
}