#include "Input.h"

namespace Input {
	std::array<char, Keyboard::GetKeyBufferSize()> Keyboard::inputBuffer;
	std::array<char, Keyboard::GetKeyBufferSize()> Keyboard::inputBuffer_prev;

	std::array<bool, Keyboard::GetKeyBufferSize()> Keyboard::isKeyDown;
	std::array<bool, Keyboard::GetKeyBufferSize()> Keyboard::isKeyUp;

	//--------------------------------------------------

	void Keyboard::Init()
	{
		inputBuffer.fill(0);
		inputBuffer_prev.fill(0);

		isKeyDown.fill(false);
		isKeyUp.fill(false);
	}

	void Keyboard::Update()
	{
		// 前フレームの入力情報をセット
		for (int i = 0; i < BUFFER_SIZE; i++) {
			inputBuffer_prev[i] = inputBuffer[i];
		}

		GetHitKeyStateAll(inputBuffer.data());				// 配列にキー情報格納

		// キー情報セット
		for (int i = 0; i < BUFFER_SIZE; i++) {
			int keyXor = inputBuffer[i] ^ inputBuffer_prev[i];
			isKeyDown[i] = keyXor & inputBuffer[i];
			isKeyUp[i] = keyXor & inputBuffer_prev[i];
		}
	}

	//--------------------------------------------------

	bool Keyboard::GetKey(int key)
	{
		if (inputBuffer[key]) return true;

		return false;
	}

	bool Keyboard::GetKeyDown(int key)
	{
		if (isKeyDown[key]) return true;

		return false;
	}

	bool Keyboard::GetKeyUp(int key)
	{
		if (isKeyUp[key]) return true;

		return false;
	}
}