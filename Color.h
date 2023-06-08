#pragma once
#include"DxLib.h"

// UnityみたいなColorクラス作ったけど、そもそもDxLib側のメソッドに対応してないから無意味だった

struct Color
{
	// 色の要素
	int r;
	int g;
	int b;
	int a;

	// 色のテンプレ
	static unsigned int Red() { return GetColor(255, 0, 0); }
	static unsigned int Blue()		{ return GetColor(  0, 255,   0); }
	static unsigned int Green()		{ return GetColor(  0,   0, 255); }

	static unsigned int White()		{ return GetColor(255, 255, 255); }
	static unsigned int Black()		{ return GetColor(  0,   0,   0); }
	static unsigned int Gray()		{ return GetColor(128, 128, 128); }

	static unsigned int Yellow()	{ return GetColor(255, 255,   0); }
	static unsigned int Cyan()		{ return GetColor(  0, 255, 255); }
	static unsigned int Magenta()	{ return GetColor(255,   0, 255); }		
};