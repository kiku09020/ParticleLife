#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
private:
	float zoomDistance = 3.0f;			// �Y�[������
	const float zoomableMin = -30;		// �Y�[���A�E�g�ł���ŏ��l
	const float zoomableMax = 30;		// �Y�[���C���ł���ő�l
	
	// �Y�[��
	void Zoom();

	// �ړ�
	void Move();

public:
	// �R���X�g���N�^
	Camera();

	// �w�肳�ꂽ�Y�[���ʂɉ����ăY�[��
	void Zoom(int zoomDistance);

	void Init() override;
	void Update() override;
};
