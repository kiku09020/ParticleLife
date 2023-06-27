#pragma once
#include "DxLib.h"
#include <array>
#include <iostream>

//--------------------------------------------------

namespace Input {
	class Mouse
	{
		static const int BUFFER_SIZE = 3;							// 入力のバッファサイズ

		static std::array<char, BUFFER_SIZE> inputBuffer;			// 入力バッファ
		static std::array<char, BUFFER_SIZE> inputBuffer_prev;		// 前フレームの入力バッファ

		static std::array<bool, BUFFER_SIZE> isKeyDown;				// 入力された瞬間
		static std::array<bool, BUFFER_SIZE> isKeyUp;				// 入力が離された瞬間

		//--------------------------------------------------
		// *MousePosition
		static const VECTOR START_MOUSE_POSITION;					// 最初のマウスポインタの位置
		static VECTOR prevMousePosition;							// 前フレームのマウスポインタの位置
		static VECTOR mousePosition;								// マウスポインタの位置

		// *MouseWheel
		static bool isWheelForward;									// マウスホイールが前方向にスクロールされたか
		static bool isWheelBack;									// マウスホイールが後ろ方向にスクロールされたか

		// マウスボタンのコードを取得
		static int CheckMouseButtonCode(int keyCode);
		static void SetMousePosition();								// マウスポインタの位置をセットする
		static void SetMouseWheelState();							// マウスホイールの状態を取得する
		//--------------------------------------------------

	public:
		static void Init();
		static void Update();

		// Getter
		static bool GetMouseButton(int button);
		static bool GetMouseButtonDown(int button);
		static bool GetMouseButtonUp(int button);

		static constexpr int GetMouseBufferSize()	{ return BUFFER_SIZE; }
		static VECTOR GetMousePosition()			{ return mousePosition; }		// マウスポインタの位置を取得する

		// 移動量を取得する
		static VECTOR GetMouseMoveDelta();

		static bool GetIsWheelForward()				{ return isWheelForward; }
		static bool GetIsWheelBack()				{ return isWheelBack; }
	};

	static class Keyboard
	{
		static const int BUFFER_SIZE = 256;							// 入力のバッファサイズ

		static std::array<char, BUFFER_SIZE> inputBuffer;			// 入力バッファ
		static std::array<char, BUFFER_SIZE> inputBuffer_prev;		// 前フレームの入力バッファ

		static std::array<bool, BUFFER_SIZE> isKeyDown;				// 入力された瞬間
		static std::array<bool, BUFFER_SIZE> isKeyUp;				// 入力が離された瞬間

	public:
		static void Init();
		static void Update();

		static bool GetKey(int key);
		static bool GetKeyDown(int key);
		static bool GetKeyUp(int key);

		static constexpr int GetKeyBufferSize() { return BUFFER_SIZE; }
	};
}