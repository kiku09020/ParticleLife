#include "Input.h"

namespace Input {
	std::array<char, Mouse::GetMouseBufferSize()> Mouse::inputBuffer;
	std::array<char, Mouse::GetMouseBufferSize()> Mouse::inputBuffer_prev;

	std::array<bool, Mouse::GetMouseBufferSize()> Mouse::isKeyDown;
	std::array<bool, Mouse::GetMouseBufferSize()> Mouse::isKeyUp;

	VECTOR Mouse::mousePosition;

	//--------------------------------------------------

	void Mouse::Init()
	{
		inputBuffer.fill(0);
		inputBuffer_prev.fill(0);
		isKeyDown.fill(false);
		isKeyUp.fill(false);
	}

	void Mouse::Update()
	{
		SetMousePosition();		// マウス位置を求める

		// 前フレームの入力情報をセット
		for (int i = 1; i < BUFFER_SIZE; i++) {
			inputBuffer_prev[i] = inputBuffer[i];
		}

		// キー情報セット
		inputBuffer[1] = GetMouseInput() & MOUSE_INPUT_LEFT;		// 左クリック
		inputBuffer[2] = GetMouseInput() & MOUSE_INPUT_RIGHT;		// 右クリック
		inputBuffer[3] = GetMouseInput() & MOUSE_INPUT_MIDDLE;		// マウスホイール押し込み

		for (int i = 0; i < BUFFER_SIZE; i++) {
			int keyXor = inputBuffer[i] ^ inputBuffer_prev[i];
			isKeyDown[i] = keyXor & inputBuffer[i];
			isKeyUp[i] = keyXor & inputBuffer_prev[i];
		}
	}

	//--------------------------------------------------

	void Mouse::SetMousePosition()
	{
		int x = (int)mousePosition.x;
		int y = (int)mousePosition.y;

		GetMousePoint(&x, &y);			// マウス位置取得

		mousePosition = VGet((float)x, (float)y, 0);
	}

	bool Mouse::GetMouseButton(int button)
	{
		if (inputBuffer[button]) return true;

		return false;
	}

	bool Mouse::GetMouseButtonDown(int button)
	{
		if (isKeyDown[button]) return true;

		return false;
	}

	bool Mouse::GetMouseButtonUp(int button)
	{
		if (isKeyUp[button]) return true;

		return false;
	}
}