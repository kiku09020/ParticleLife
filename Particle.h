#pragma once
#include"DxLib.h"
#include "Color.h"

class Particle
{
private:
	float size;				// 大きさ
	VECTOR position;		// 位置
	


	// 位置をランダムで指定
	void SetPosition();


public:
	// コンストラクタ
	Particle();


};
