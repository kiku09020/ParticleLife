#pragma once
#include"DxLib.h"

// UnityみたいなColorクラス作ったけど、そもそもDxLib側のメソッドに対応してないから無意味だった

struct Color
{
	// 色の要素
	int r;	int g;	int b;	int a;

	// コンストラクタ
	Color(int r, int g, int b, int a = 1)
	{	this->r = r;	this->g = g;	this->b = b;	this->a = a;	}

	//--------------------------------------------------
	// 色のテンプレ
	
	// 赤
	static unsigned int Red()		{ return GetColor(255,   0,   0); }
	// 青
	static unsigned int Blue()		{ return GetColor(  0, 255,   0); }
	// 緑
	static unsigned int Green()		{ return GetColor(  0,   0, 255); }

	// 白
	static unsigned int White()		{ return GetColor(255, 255, 255); }
	// 黒
	static unsigned int Black()		{ return GetColor(  0,   0,   0); }
	// 灰
	static unsigned int Gray()		{ return GetColor(128, 128, 128); }

	// 黄
	static unsigned int Yellow()	{ return GetColor(255, 255,   0); }
	// 水色
	static unsigned int Cyan()		{ return GetColor(  0, 255, 255); }
	// 赤紫
	static unsigned int Magenta()	{ return GetColor(255,   0, 255); }

	//--------------------------------------------------
	// RGB取得用

	// 赤色のRGB
	static Color RedWithRGB()		{ return Color(255,   0,   0); }
	// 青色のRGB
	static Color BlueWithRGB()		{ return Color(  0, 255,   0); }
	// 緑色のRGB
	static Color GreenWithRGB()		{ return Color(  0,   0, 255); }

	// 白色のRGB
	static Color WhiteWithRGB()		{ return Color(255, 255, 255); }
	// 黒色のRGB
	static Color BlackWithRGB()		{ return Color(  0,   0,   0); }
	// 灰色のRGB
	static Color GrayWithRGB()		{ return Color(128, 128, 128); }

	// 黄色のRGB
	static Color YellowWithRGB()	{ return Color(255, 255,   0); }
	// 水色のRGB
	static Color CyanWithRGB()		{ return Color(  0, 255, 255); }
	// 赤紫色のRGB
	static Color MagentaWithRGB()	{ return Color(255,   0, 255); }
};