#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
private:
	const float zoomableRegion = 100;
	float zoomDistance = zoomableRegion / 7.5f;			// �Y�[������
	
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
