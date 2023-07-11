#pragma once
#include "DxLib.h"



class UIManager
{
private:
	static const inline int FONT_SIZE = 12;
	static const inline int FONT_THICKNESS = 1;

	// “ü—Í”»’è
	static void CheckInput();
	// GUI‚Ì•`‰æ
	static void GUIRender();

	static void RenderTest();

public:
	static void Init();
	static void Update();
	static void OnEnd();
};
