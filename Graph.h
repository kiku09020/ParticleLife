#pragma once
#include "DxLib.h"

#include "Camera.h"

#include <type_traits>
#include <vector>

// �}�`���N���X
class Graph
{
protected:
	int color;							// �F
	bool isFilled;						// ������������
	float lineThickness = 1.0f;			// �O�g�̑���

	static const inline float graphRenderSize = 32.0f;		// �}�`���ʂ̕`��T�C�Y

public:
	// �R���X�g���N�^
	Graph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:color(color), isFilled(isFilled), lineThickness(thickness){}

	virtual void Draw(Camera*, GameObject*) = 0;
};

class IRotatable
{
protected:
	#define VECTOR_X = VGet(1, 0, 0)
	#define VECTOR_Y = VGet(0, 1, 0)
	#define VECTOR_Z = VGet(0, 0, 1)

	// �s����l���������_���W���擾����
	void GetMatrixedVertices(VECTOR axis, float rotate, std::vector<VECTOR>* vertices, Camera* camera, GameObject* gameObject);

	void GetMatrixedVertices(std::vector<VECTOR>*, Camera*, GameObject*);
};

//--------------------------------------------------

// �~
class CircleGraph : public Graph
{
private:
	int pointCount;			// �~�̒��_�̐�

public:
	// �R���X�g���N�^
	CircleGraph(int ptCount = 32, int color = Color::White(), bool isFilled = true, float thickness = 1)
		: Graph(color, isFilled, thickness), pointCount(ptCount){}

	void Draw(Camera*, GameObject*) override;
};

// ��`
class RectangleGraph : public Graph, IRotatable
{
public:
	// �R���X�g���N�^
	RectangleGraph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Graph(color, isFilled, thickness){}

	void Draw(Camera*, GameObject*) override;
};

// �O�p�`
class TriangleGraph :public Graph
{
public:
	TriangleGraph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Graph(color, isFilled, thickness){}

	void Draw(Camera*, GameObject*) override;
};