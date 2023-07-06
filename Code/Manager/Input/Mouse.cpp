#include "Input.h"

namespace Input {
	std::array<char, Mouse::GetMouseBufferSize()> Mouse::inputBuffer;
	std::array<char, Mouse::GetMouseBufferSize()> Mouse::inputBuffer_prev;

	std::array<bool, Mouse::GetMouseBufferSize()> Mouse::isKeyDown;
	std::array<bool, Mouse::GetMouseBufferSize()> Mouse::isKeyUp;

	VECTOR Mouse::prevMousePosition;
	VECTOR Mouse::mousePosition;

	bool Mouse::isWheelBack;
	bool Mouse::isWheelForward;

	//--------------------------------------------------

	void Mouse::Init()
	{
		inputBuffer.fill(0);
		inputBuffer_prev.fill(0);
		isKeyDown.fill(false);
		isKeyUp.fill(false);

		isWheelBack = false;
		isWheelForward = false;

		prevMousePosition = VGet(0, 0, 0);
		mousePosition = VGet(0, 0, 0);
	}

	void Mouse::Update()
	{
		// マウス位置の入力情報を取得
		SetMousePosition();

		// マウスホイールの入力情報を取得
		SetMouseWheelState();

		/* マウスキー入力 */
		// 前フレームの入力情報をセット
		for (int i = 0; i < BUFFER_SIZE; i++) {
			inputBuffer_prev[i] = inputBuffer[i];
		}

		// キー情報セット
		inputBuffer[0] = GetMouseInput() & MOUSE_INPUT_LEFT;		// 左クリック
		inputBuffer[1] = GetMouseInput() & MOUSE_INPUT_RIGHT;		// 右クリック
		inputBuffer[2] = GetMouseInput() & MOUSE_INPUT_MIDDLE;		// マウスホイール押し込み

		for (int i = 0; i < BUFFER_SIZE; i++) {
			int keyXor   = inputBuffer[i] ^ inputBuffer_prev[i];
			isKeyDown[i] = keyXor & inputBuffer[i];
			isKeyUp[i]   = keyXor & inputBuffer_prev[i];
		}
	}

	//--------------------------------------------------

	void Mouse::SetMousePosition()
	{
		prevMousePosition = mousePosition;		// 前フレームののマウス位置指定

		int x = (int)mousePosition.x;
		int y = (int)mousePosition.y;

		GetMousePoint(&x, &y);					// マウス位置取得

		mousePosition = VGet((float)x, (float)y, 0);
	}

	void Mouse::SetMouseWheelState()
	{
		// 前フレームの入力情報をリセット
		isWheelBack = false;
		isWheelForward = false;

		// マウスホイールの値を取得
		int mouseWheel = GetMouseWheelRotVol();

		// 手前にスクロール
		if (mouseWheel < 0) {
			isWheelBack = true;
		}

		// 奥にスクロール
		else if (mouseWheel > 0) {
			isWheelForward = true;
		}
	}

	//--------------------------------------------------

	int Mouse::CheckMouseButtonCode(int keyCode)
	{
		int exponent = 0;		

		while (keyCode > 1) {
			if (keyCode % 2 != 0) { return -1; }

			keyCode /= 2;
			exponent++;
		}

		return exponent;
	}

	bool Mouse::GetMouseButton(int button)
	{
		int index = CheckMouseButtonCode(button);

		if (inputBuffer[index]) return true;

		return false;
	}

	bool Mouse::GetMouseButtonDown(int button)
	{
		int index = CheckMouseButtonCode(button);

		if (isKeyDown[index]) return true;

		return false;
	}

	bool Mouse::GetMouseButtonUp(int button)
	{
		int index = CheckMouseButtonCode(button);

		if (isKeyUp[index]) return true;

		return false;
	}

	//--------------------------------------------------

	VECTOR Mouse::GetMouseMoveDelta()
	{
		VECTOR delta;

		delta.x = mousePosition.x - prevMousePosition.x;
		delta.y = mousePosition.y - prevMousePosition.y;

		return delta;
	}
}