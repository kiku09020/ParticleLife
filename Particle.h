#pragma once
#include"DxLib.h"
#include "Color.h"

class Particle
{
private:
	float size;				// �傫��
	VECTOR position;		// �ʒu
	Color color;			// �F


	// �ʒu�������_���Ŏw��
	void SetPosition();


public:
	// �R���X�g���N�^
	Particle();


};
