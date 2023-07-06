#pragma once
#include "DxLib.h"
#include "Extensions/Color.h"

class Transform
{
public:
	// �R���X�g���N�^
	Transform(VECTOR pos, VECTOR rot, VECTOR scl) :position(pos), rotation(rot), scale(scl) {}

	VECTOR position = VGet(0, 0, 0);
	VECTOR rotation = VGet(0, 0, 0);
	VECTOR scale	= VGet(1, 1, 1);
};

class GameObject
{
private:
	bool activate = true;

public:
	Transform transform;

	// �R���X�g���N�^
	GameObject(Transform tf) :transform(tf) {}

	//--------------------------------------------------
	// ������
	virtual void Init() = 0;

	// �X�V����
	virtual void Update() = 0;

	//--------------------------------------------------

	// �I�u�W�F�N�g�̃A�N�e�B�u��
	void SetActive(bool);
};
