#pragma once
#include "DxLib.h"
#include "Color.h"

class Transform
{
public:
	VECTOR position;
	VECTOR rotation;
	VECTOR scale = VGet(1, 1, 1);
};

class GameObject
{
private:
	bool activate = true;

protected:
	// �`�揈��
	virtual void Draw() = 0;

public:
	Transform transform;

	GameObject(VECTOR);

	//--------------------------------------------------
	// ������
	virtual void Init() = 0;

	// �X�V����
	virtual void Update() = 0;

	//--------------------------------------------------

	// �I�u�W�F�N�g�̃A�N�e�B�u��
	void SetActive(bool);
};
