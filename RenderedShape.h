#pragma once
#include "DxLib.h"

#include "Camera.h"

#include <type_traits>
#include <vector>

#include "RendereredObject.h"

class ShapeBase:RenderedObject {
protected:
	int color;

};

// ���ʐ}�`���N���X
class Shape2D:public ShapeBase,public IRenderedObject2D
{
protected:
	bool isFilled;						// ������������
	float lineThickness = 1.0f;			// �O�g�̑���

public:
	// �R���X�g���N�^
	Shape2D(int, bool, float, float);

	virtual void Drawn(Camera*, GameObject*) override;
};

class Shape3D :public ShapeBase, public IRenderedObject3D {

};

//--------------------------------------------------

// �~
class CircleShape : public Shape2D
{
private:
	int pointCount;			// �~�̒��_�̐�

public:
	// �R���X�g���N�^
	CircleShape(int ptCount = 32, int color = Color::White(), bool isFilled = true, float thickness = 1)
		: Shape2D(color, isFilled, thickness,4), pointCount(ptCount){}

	void Drawn(Camera*, GameObject*) override;
};

// ��`
class RectangleShape : public Shape2D
{
public:
	// �R���X�g���N�^
	RectangleShape(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Shape2D(color, isFilled, thickness,4){}

	void Drawn(Camera*, GameObject*) override;
};

// �O�p�`
class TriangleShape :public Shape2D
{
public:
	TriangleShape(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Shape2D(color, isFilled, thickness,4){}

	void Drawn(Camera*, GameObject*) override;
};