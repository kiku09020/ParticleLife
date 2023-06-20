#pragma once
#include"DxLib.h"

// Unity�݂�����Color�N���X��������ǁA��������DxLib���̃��\�b�h�ɑΉ����ĂȂ����疳�Ӗ�������

struct Color
{
	// �F�̗v�f
	int r;	int g;	int b;	int a;

	// �R���X�g���N�^
	Color(int r, int g, int b, int a = 1)
	{	this->r = r;	this->g = g;	this->b = b;	this->a = a;	}

	//--------------------------------------------------
	// �F�̃e���v��
	
	// ��
	static unsigned int Red()		{ return GetColor(255,   0,   0); }
	// ��
	static unsigned int Blue()		{ return GetColor(  0, 255,   0); }
	// ��
	static unsigned int Green()		{ return GetColor(  0,   0, 255); }

	// ��
	static unsigned int White()		{ return GetColor(255, 255, 255); }
	// ��
	static unsigned int Black()		{ return GetColor(  0,   0,   0); }
	// �D
	static unsigned int Gray()		{ return GetColor(128, 128, 128); }

	// ��
	static unsigned int Yellow()	{ return GetColor(255, 255,   0); }
	// ���F
	static unsigned int Cyan()		{ return GetColor(  0, 255, 255); }
	// �Ԏ�
	static unsigned int Magenta()	{ return GetColor(255,   0, 255); }

	//--------------------------------------------------
	// RGB�擾�p

	// �ԐF��RGB
	static Color RedWithRGB()		{ return Color(255,   0,   0); }
	// �F��RGB
	static Color BlueWithRGB()		{ return Color(  0, 255,   0); }
	// �ΐF��RGB
	static Color GreenWithRGB()		{ return Color(  0,   0, 255); }

	// ���F��RGB
	static Color WhiteWithRGB()		{ return Color(255, 255, 255); }
	// ���F��RGB
	static Color BlackWithRGB()		{ return Color(  0,   0,   0); }
	// �D�F��RGB
	static Color GrayWithRGB()		{ return Color(128, 128, 128); }

	// ���F��RGB
	static Color YellowWithRGB()	{ return Color(255, 255,   0); }
	// ���F��RGB
	static Color CyanWithRGB()		{ return Color(  0, 255, 255); }
	// �Ԏ��F��RGB
	static Color MagentaWithRGB()	{ return Color(255,   0, 255); }
};