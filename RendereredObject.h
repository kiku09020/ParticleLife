#pragma once

#include "Camera.h"
#include <vector>

class RenderedObject {
protected:
	// �e�I�u�W�F�N�g�̕`�揈���{��
	virtual void DrawingProcess(Camera*camera,GameObject* gameObject) = 0;

public:
	// �`�揀�� + �`�揈��
	virtual void Drawn(Camera* camera, GameObject* gameObject) 
	{
		DrawingProcess(camera, gameObject);
	};
};

// 2D�`�悳���I�u�W�F�N�g�C���^�[�t�F�[�X�N���X
class IRenderedObject2D:public RenderedObject
{
protected:
	float pixelsPerUnit = 1;			// �`��T�C�Y�B(Unity�̃t�B�[���h���p�N���������B
	VECTOR graphicSize;					// �`�悳���T�C�Y
	std::vector<VECTOR> vertices;		// ���_���X�g

	//--------------------------------------------------

	IRenderedObject2D(float ppu);

	// �O���t�T�C�Y�w��
	virtual void SetGraphSize(VECTOR, Camera*);

	// ���_�ǉ�
	virtual void AddVertices();

	// ���_�ʒu�̍X�V
	virtual void SetVertices();

	// �s����l���������_���W���擾����
	void SetMatrixedVertices(Camera*, GameObject*);

	virtual void Drawn(Camera*, GameObject*) override;

	//--------------------------------------------------
	/* setter */
	// pixelPerUnit�̕ύX
	void SetPPU(float ppu) { pixelsPerUnit = ppu; }
};

// 3D�`�悳���I�u�W�F�N�g�C���^�[�t�F�[�X�N���X
class IRenderedObject3D:public RenderedObject
{

};